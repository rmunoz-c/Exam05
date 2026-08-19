#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_map(char *map, int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (map[y * w + x])
				putchar('O');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

int count_neighbours(char *map, int x, int y, int w, int h)
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
			if (0 <= cy && cy < h && 0 <= cx && cx < w)
				count += map[cy * w + cx];
		}
	}
	return (count);
}

void update(char *map, char *new, int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int neighbours = count_neighbours(map, x, y, w, h);
			if ((map[y * w + x] && (neighbours == 2 || neighbours == 3)) || (!map[y * w + x] && neighbours == 3))
				new[y * w + x] = 1;
			else
				new[y * w + x] = 0;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	int w = atoi(argv[1]);
	int h = atoi(argv[2]);
	int iters = atoi(argv[3]);
	char *map = calloc(w * h, 1);
	char *new = calloc(w * h, 1);
	if (!map)
		return (1);
	else if (!new)
		return (free(map), 1);
	bool draw = false;
	int x = 0, y = 0;
	char c;
	
	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			draw = !draw;
		else if (c == 'a' && 0 < x)
			x--;
		else if (c == 'd' && x < (w - 1))
			x++;
		else if (c == 'w' && 0 < y)
			y--;
		else if (c == 's' && y < (h - 1))
			y++;
		if (draw)
			map[y * w + x] = 1;
	}
	for (int i = 0; i < iters; i++)
	{
		update(map, new, w, h);
		char *temp = map;
		map = new;
		new = temp;
	}
	print_map(map, w, h);
	free(map);
	free(new);
	return (0);
}
