/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:38:04 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/07 13:33:54 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	**create_point_map(t_map *map)
{
	t_point	**point_map;
	int		i;

	point_map = (t_point **)malloc(sizeof(t_point *) * map->total_rows + 1);
	if (!point_map)
		return (NULL);
	i = 0;
	while (i < map->total_rows)
	{
		point_map[i] = (t_point *)malloc(sizeof(t_point) * map->total_cols + 1);
		if (!point_map[i])
		{
			free_point_map(point_map);
			return (NULL);
		}
		i++;
	}
	return (point_map);
}

void	count_items(char item, t_map *map, int i, int j)
{
	if (item == 'C')
	{
		map->collectibles++;
	}
	if (item == 'P')
	{
		if (map->player_dup == 0)
			map->player_dup = 1;
		else
			map->point_map[i][j].type = '0';
	}
}

void	fill_neighbors(t_map *map, t_point **point_map, int i, int j)
{
	if (i > 0)
		point_map[i][j].up = &point_map[i - 1][j];
	else
		point_map[i][j].up = NULL;
	if (i < map->total_rows - 1)
		point_map[i][j].down = &point_map[i + 1][j];
	else
		point_map[i][j].down = NULL;
	if (j > 0)
		point_map[i][j].left = &point_map[i][j - 1];
	else
		point_map[i][j].left = NULL;
	if (j < map->total_cols - 1)
		point_map[i][j].right = &point_map[i][j + 1];
	else
		point_map[i][j].right = NULL;
}

t_point	**fill_point_map(t_list *head, t_map *map)
{
	int		i;
	int		j;
	t_point	**point_map;

	point_map = create_point_map(map);
	if (!point_map)
		return (NULL);
	map->point_map = point_map;
	while (head != NULL)
	{	
		i = head->index;
		j = 0;
		while (head->line[j])
		{
			point_map[i][j].type = head->line[j];
			point_map[i][j].y = i;
			point_map[i][j].x = j;
			count_items(point_map[i][j].type, map, i, j);
			fill_neighbors(map, point_map, i, j);
			j++;
		}
		head = head->next;
	}
	point_map[map->total_rows] = NULL;
	return (point_map);
}

int	free_point_map(t_point	**point_map)
{
	int	i;

	i = 0;
	while (point_map[i])
	{	
		free(point_map[i]);
		point_map[i] = NULL;
		i++;
	}
	free(point_map);
	point_map = NULL;
	return (1);
}
