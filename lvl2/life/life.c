#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

void print_map(char *map, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (map[y * width + x])
                putchar('O');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

int count_neightbours(char *map, int x, int y, int width, int height)
{
    int count = 0;
    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            if (dy == 0 && dx == 0)
                continue;
            int cy = y + dy;
            int cx = x + dx;
            if (0 <= cy && cy < height && 0 <= cx && cx < width)
                count += map[cy * width + cx];
        }
    }
    return (count);
}

void update(char *map, char *new, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int neighbours = count_neightbours(map, x, y, width, height);
            if ((map[y * width + x] && (neighbours == 2 || neighbours ==3))||(!map[y * width + x] && neighbours == 3))
                new[y * width + x] = 1;
            else
                new[y * width + x] = 0;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return (1);
    
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int iter = atoi(argv[3]);

    char *map = calloc(width * height, 1);
    if (!map)
        return (1);
    char *new = calloc(width * height, 1);
    if (!new)
        return (free(map), 1);
    int x = 0;
    int y = 0;
    char c;
    bool draw = false;
    while(read(0, &c, 1) > 0)
    {
        if (c == 'x')
            draw = !draw;
        else if (c == 'a' && 0 < x)
            x--;
        else if (c == 'd' && x < (width - 1))
            x++;
        else if (c == 'w' && 0 < y)
            y--;
        else if (c == 's' && y < (height - 1))
            y++;
        if (draw)
            map[y * width + x] = 1;
    }
    for (int i = 0; i < iter; i++)
    {
        update(map, new, width, height);
        char *temp = map;
        map = new;
        new = temp;
    }
    print_map(map, width, height);
    free(map);
    free(new);
    return (0);
}












