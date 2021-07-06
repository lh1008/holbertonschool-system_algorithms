#include "pathfinding.h"

/**
 * backtracking_array - entry to backtracking array
 * Desc: backtracking_array function that searches for the path from a
 * starting point to a target point within a two-dimensional array
 * @map: pointer to a read-only two-dimensional array
 * @rows: rows of map
 * @col: columns of map
 * @start: data structure to store the cordinates of the starting point
 * @target: data structure to store the cordinates of the target point
 * Return: return a queue, in which each node is a point in path
 * from start to target
 */
queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target)
{
	char *mapper = *map;
	int r = rows, c = cols;
	point_t *box;
	queue_t *q_box;

	box = malloc(sizeof(point_t));
	if (!box)
		return (NULL);
	box->x = r;
	box->y = c;

	q_box = malloc(sizeof(queue_t));
	if (!q_box)
		return (NULL);

	if (mapper == NULL)
	{
		return (NULL);
	}

	if (box == start || box == target)
		return (q_box);
	printf("%s\n", mapper);
	return (q_box);

}
