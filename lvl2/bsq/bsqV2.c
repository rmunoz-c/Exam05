#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>

typedef struct s_bsq
{
	char	**row;
	int		rows;
	int		cols;
	char	empty;
	char	obst;
	char	full;
}	t_bsq;

static void	free_rows(char **row, int n)
{
	while (n-- > 0)
		free(row[n]);
	free(row);
}

static int	parse_header(FILE *f, t_bsq *b)
{
	if (fscanf(f, "%d %c %c %c", &b->rows, &b->empty, &b->obst, &b->full) != 4 ||
		b->rows <= 0)
		return 0;
	return (b->empty != b->obst && b->empty != b->full && b->obst != b->full);
}

static int	read_map(FILE *f, t_bsq *b)
{
	char	*buf = NULL;
	size_t	cap = 0;
	int		i = 0;

	if (!parse_header(f, b))
		return (free(buf), 0);
	b->row = calloc((size_t)b->rows, sizeof(char *));
	if (!b->row)
		return (free(buf), 0);
	getline(&buf, &cap, f);
	while (i < b->rows)
	{
		ssize_t	len = getline(&buf, &cap, f);
		if (len < 2 || buf[len - 1] != '\n')
			break ;
		buf[--len] = '\0';
		if (i == 0)
			b->cols = (int)len;
		if (len != b->cols)
			break ;
		b->row[i++] = buf;
		buf = NULL;
		cap = 0;
	}
	if (i == b->rows && getline(&buf, &cap, f) == -1)
		return (free(buf), 1);
	free(buf);
	free_rows(b->row, i);
	return (0);
}

static int	solve(t_bsq *b)
{
	int	*dp = calloc((size_t)b->cols + 1, sizeof(int));
	int	best = 0, br = 0, bc = 0;

	if (!dp)
		return (0);
	for (int i = 0; i < b->rows; i++)
	{
		int	diag = 0;
		for (int j = 0; j < b->cols; j++)
		{
			int	up = dp[j + 1];
			if (b->row[i][j] == b->empty)
			{
				int	v = up < dp[j] ? up : dp[j];
				if (diag < v)
					v = diag;
				dp[j + 1] = ++v;
				if (v > best)
				{
					best = v;
					br = i;
					bc = j;
				}
			}
			else if (b->row[i][j] == b->obst)
				dp[j + 1] = 0;
			else
				return (free(dp), 0);
			diag = up;
		}
	}
	free(dp);
	for (int i = br - best + 1; i <= br; i++)
	{
		for (int j = bc - best + 1; j <= bc; j++)
			b->row[i][j] = b->full;
	}
	return (1);
}

static void	bsq(FILE *f)
{
	t_bsq	b;

	if (!read_map(f, &b))
	{
		fputs("map error3\n", stderr);
		return ;
	}
	if (solve(&b))
		for (int i = 0; i < b.rows; i++)
		{
			fputs(b.row[i], stdout);
			fputs("\n", stdout);
		}
	else
		fputs("map error1\n", stderr);
	free_rows(b.row, b.rows);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		bsq(stdin);
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		FILE	*f = fopen(argv[i], "r");

		if (!f)
		{
			fputs("map error2\n", stderr);
			continue ;
		}
		bsq(f);
		fclose(f);
	}
	return (0);
}
