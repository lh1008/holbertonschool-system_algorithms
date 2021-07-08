#include "pathfinding.h"
#include "graphs.h"
#include "queues.h"

/**
 * back_track - entry to backtracking
 * Desc: backtracking function that makes a recursive backtracking
 * to find the first working path from start to target
 * @map: double pointer
 * @x: int x
 * @y: int y
 * @rows: int rows
 * @cols: int cols
 * @start: const structure start
 * @target: const structure target
 * @path: pointet to path from recursive backtracking
 * Return: 1
 */
int back_track(char **map, int x, int y,  int rows, int cols,
		 point_t const *start, point_t const *target, queue_t **path)
{
	int right = 0, bottom = 0, left = 0, up = 0;
	point_t *current;

	current = malloc(sizeof(*current));
	if (!current)
		return (0);
	current->x = x;
	current->y = y;
	printf("Checking coordinates [%i, %i]\n", x, y);
	map[y][x] = '1';
	if (target->x == x && target->y == y)
	{
		queue_push_front(*path, current);
		return (1);
	}
	if (x + 1 < cols)
		if (map[y][x + 1] == '0')
			right = back_track((char **)map, x + 1, y,
					     rows, cols, start, target, path);
	if (y + 1 < rows)
		if (map[y + 1][x] == '0' && right != 1)
			bottom = back_track((char **)map, x, y + 1,
					      rows, cols, start, target, path);
	if (x - 1 >= 0)
		if (map[y][x - 1] == '0' && right != 1
		    && bottom != 1)
			left = back_track((char **)map, x - 1, y,
					    rows, cols, start, target, path);
	if (y - 1 >= 0)
		if (map[y - 1][x] == '0' && right != 1
		    && bottom != 1 && left != 1)
			up = back_track((char **)map, x, y - 1,
					  rows, cols, start, target, path);
	if (right == 0 && bottom == 0 && left == 0 && up == 0)
	{
		free(current);
		return (0);
	}
	queue_push_front(*path, current);
	return (1);
}

/**
 * backtracking_array - entry to backtracking array
 * Desc: backtracking_array function that searches for the path from a
 * starting point to a target point within a two-dimensional array
 * @map: pointer to a read-only two-dimensional array
 * @rows: rows of map
 * @cols: columns of map
 * @start: data structure to store the cordinates of the starting point
 * @target: data structure to store the cordinates of the target point
 * Return: return a queue, in which each node is a point in path
 * from start to target
 */
queue_t *backtracking_array(char **map, int rows, int cols,
			    point_t const *start, point_t const *target)
{
	queue_t *path;
	int x, y, i, ret;
	char **map2;

	if (!map || !*map || !start || !target || rows < 1 || cols < 1)
		return (NULL);
	map2 = malloc(rows * sizeof(char *));
	if (!map2)
		exit(1);
	for (i = 0; i < rows; i++)
	{
		map2[i] = malloc(cols + 1);
		if (!map2[i])
			exit(1);
		strcpy(map2[i], map[i]);
	}
	path = queue_create();
	if (path == NULL)
		return (0);
	x = start->x;
	y = start->y;
	ret = back_track(map2, x, y, rows, cols, start, target, &path);
	if (!ret)
		queue_delete(path), path = NULL;
	for (i = 0; i < rows; i++)
		free(map2[i]);
	free(map2);
	return (path);
}
