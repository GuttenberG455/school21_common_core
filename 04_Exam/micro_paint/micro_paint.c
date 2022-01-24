#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_field
{
    int width;
    int height;
    char backgrond;
} t_field;

typedef struct s_rect
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
} t_rect;

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
    return (1);
}

int free_all(FILE *file, char *draw)
{
    fclose(file);
    if (draw)
        free(draw);
    return (1);
}

int check_field(t_field *field)
{
    return ((field->width >= 0 && field->width <= 300) && (field->height >= 0 && field->height <= 300));
}

char *get_field(FILE *file, t_field *field)
{
    int count;
    char *array;
    int i = 0;

    if ((count = fscanf(file, "%d %d %c\n", &field->width, &field->height, &field->backgrond)) != 3)
        return (0);
    if (count == (-1))
        return (0);
    if (!(check_field(field)))
        return (0);
    array = (char *)malloc(sizeof(char) * (field->width * field->height));
    while (i < field->width * field->height)
    {
        array[i] = field->backgrond;
        i++;
    }
    return (array);
}

int check_tmp(t_rect *tmp)
{
    return ((tmp->height > 0.00000000 && tmp->width > 0.00000000) && (tmp->type == 'r' || tmp->type == 'R'));
}

int is_rec(float y, float x, t_rect *tmp)
{
    float check = 1.00000000;
    if ((x < tmp->x) || (tmp->x + tmp->width < x) || (y < tmp->y) || (tmp->y + tmp->height < y))
        return (0);
    if (((x - tmp->x) < check) || ((tmp->x + tmp->width) - x < check) || ((y - tmp->y) < check) || ((tmp->y + tmp->height) - y < check))
        return (2);
    return (1);
}

void get_draw(char **draw, t_rect *tmp, t_field *field)
{
    int x, y;
    int rec;

    y = 0;
    while (y < field->height)
    {
        x = 0;
        while (x < field->width)
        {
            rec = is_rec(y, x, tmp);
            if ((tmp->type == 'r' && rec == 2) || (tmp->type == 'R' && rec))
                (*draw)[(y * field->width) + x] = tmp->color;
            x++;
        }
        y++;
    }
}

int drawing(FILE *file, char **draw, t_field *field)
{
    t_rect tmp;
    int count;

    while ((count = fscanf(file, "%c %f %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.width, &tmp.height, &tmp.color)) == 6)
    {
        if (!(check_tmp(&tmp)))
            return (0);
        get_draw(draw, &tmp, field);
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

int main(int argc, char **argv)
{
    FILE *file;
    char *draw;
    t_field field;

    if (argc != 2)
        return (ft_close("Error: argument\n"));
    if (!(file = fopen(argv[1], "r")))
        return (ft_close("Error: Operation file corrupted\n"));
    if (!(draw = get_field(file, &field)))
        return (free_all(file, 0) && ft_close("Error: Operation file corrupted\n"));
    if (!(drawing(file, &draw, &field)))
        return (free_all(file, draw) && ft_close("Error: Operation file corrupted\n"));
    print_draw(draw, &field);
    free_all(file, draw);
    return (0);
}