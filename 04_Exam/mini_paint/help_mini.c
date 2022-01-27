#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_zone // параметры поля
{
    int width;
    int height;
    char background;
} t_zone;

typedef struct s_list // параметры прямоуг
{
    char type;
    float x;
    float y;
    float radius;
    char color;
} t_list;

int ft_strlen(char *str)
{
    int i = 0;
    if (!str)
        return (i);
    while (str[i])
        i++;
    return (i);
}

int fail(char *str) // сообщение об ошибке
{
    write(1, str, ft_strlen(str));
    return(1);
}

int free_all(FILE *file, char *str) //очистка памяти
{
    fclose(file);
    if (str)
        free(str);
    return (1);
}

char *get_zone(FILE *file, t_zone *zone) // создаем поле
{
    int i;
    char *array;

    if ((i = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background)) != 3) // берем первую строку из файла
        return (NULL);
    if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300) // проверка ввода
        return (NULL);
    if (!(array = (char *)malloc(sizeof(char) * (zone->width * zone->height)))) // выделение памяти
        return (NULL);
    i = 0;
    while (i < (zone->width * zone->height))
    {
        array[i] = zone->background; // заполнение бэкграунда
        i++;
    }
    return (array);
}

int is_rad(float x, float y, t_list *tmp)
{
    float dist;

    dist = sqrtf(((x - tmp->x) * (x - tmp->x)) + ((y - tmp->y) * (y - tmp->y)));

    if (dist <= tmp->radius) // проверка на расстояние и радиус
    {
        if ((tmp->radius - dist) < 1.00000000) // только окружность 
            return (2);
        return (1);
    }
    return (0);
}

void get_draw(t_list *tmp, t_zone *zone, char *draw)
{
    int x, y, rad;

    y = 0;
    while (y < zone->height)
    {
        x = 0;
        while (x < zone->width)
        {
            rad = is_rad((float)x, (float)y, tmp); // какой тип круга 
            if ((rad == 2 && tmp->type == 'c') || (rad && tmp->type == 'C'))
                draw[(y * zone->width) + x] = tmp->color; // заполнение только если С
            x++;
        }
        y++;
    }
}

int drawing(FILE *file, t_zone *zone, char *draw)
{
    t_list tmp;
    int count;

    while ((count = fscanf(file, "%c %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.radius, &tmp.color)) == 5) 
    {	// ввод данных о круге
        if (tmp.radius <= 0.00000000 && (tmp.type != 'c' || tmp.type != 'C'))
            return (0); // если неправильный радиус
        get_draw(&tmp, zone, draw); // рисуем
    }
    if (count != (-1))
        return (0);
    return (1);
}

void print_draw(char *draw, t_zone *zone)
{
    int i = 0;

    while (i < zone->height)
    {
        write(1, draw + (i * zone->width), zone->width);
        write(1, "\n", 1);
        i++;
    }
}

int main(int ac, char **av)
{
    t_zone zone;
    char *draw;
    FILE *file;

    if (ac != 2)
        return (fail("Error: argument\n"));
    if (!(file = fopen(av[1], "r")))
        return (fail("Error: Operation file corrupted\n"));
    if (!(draw = get_zone(file, &zone)))
        return (free_all(file, NULL) && fail("Error: Operation file corrupted\n"));
    if (!(drawing(file, &zone, draw)))
        return (free_all(file, draw) && fail("Error: Operation file corrupted\n"));
    print_draw(draw, &zone);
    free_all(file, draw);
    return (0);
}