#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_field
{
    int width;
    int height;
    char bg_ch;
} 	t_field;

typedef struct s_circle
{
    char type;
    float x;
    float y;
    float radius;
    char color;
} 	t_circle;

int ft_strlen(char *str)
{
    int i = 0;
    if (!str)
        return (i);
    while (str[i])
        i++;
    return (i);
}

int ft_close(char *str)
{
    write(1, str, ft_strlen(str));
    return(1);
}

int free_all(FILE *file, char *str)
{
    fclose(file);
    if (str)
        free(str);
    return (1);
}

char *get_field(FILE *file, t_field *field)
{
    int i;
    char *array;

    if ((i = fscanf(file, "%d %d %c\n", &field->width, &field->height, &field->bg_ch)) != 3)
        return (NULL);
    if (field->width <= 0 || field->width > 300 || field->height <= 0 || field->height > 300)
        return (NULL);
    if (!(array = (char *)malloc(sizeof(char) * (field->width * field->height))))
        return (NULL);
    i = 0;
    while (i < (field->width * field->height))
    {
        array[i] = field->bg_ch;
        i++;
    }
    return (array);
}

int is_rad(float x, float y, t_circle *tmp)
{
    float dist;

    dist = sqrtf(((x - tmp->x) * (x - tmp->x)) + ((y - tmp->y) * (y - tmp->y)));

    if (dist <= tmp->radius)
    {
        if ((tmp->radius - dist) < 1.00000000)
            return (2);
        return (1);
    }
    return (0);
}

void get_draw(t_circle *tmp, t_field *field, char *draw)
{
    int x, y, rad;

    y = 0;
    while (y < field->height)
    {
        x = 0;
        while (x < field->width)
        {
            rad = is_rad((float)x, (float)y, tmp);
            if ((rad == 2 && tmp->type == 'c') || (rad && tmp->type == 'C'))
                draw[(y * field->width) + x] = tmp->color;
            x++;
        }
        y++;
    }
}

int drawing(FILE *file, t_field *field, char *draw)
{
    t_circle tmp;
    int count;

    while ((count = fscanf(file, "%c %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.radius, &tmp.color)) == 5)
    {
        if (tmp.radius <= 0.00000000 && (tmp.type != 'c' || tmp.type != 'C'))
            return (0);
        get_draw(&tmp, field, draw);
    }
    if (count != (-1))
        return (0);
    return (1);
}

void print_draw(char *draw, t_field *field)
{
    int i = 0;

    while (i < field->height)
    {
        write(1, draw + (i * field->width), field->width);
        write(1, "\n", 1);
        i++;
    }
}

int main(int ac, char **av)
{
    t_field field;
    char *draw;
    FILE *file;

    if (ac != 2)
        return (ft_close("Error: argument\n"));
    if (!(file = fopen(av[1], "r")))
        return (ft_close("Error: Operation file corrupted\n"));
    if (!(draw = get_field(file, &field)))
        return (free_all(file, NULL) && ft_close("Error: Operation file corrupted\n"));
    if (!(drawing(file, &field, draw)))
        return (free_all(file, draw) && ft_close("Error: Operation file corrupted\n"));
    print_draw(draw, &field);
    free_all(file, draw);
    return (0);
}
