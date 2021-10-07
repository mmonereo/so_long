/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:46:15 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/07 13:27:19 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	paint_wall(t_global *global)
{
	int		i;
	int		j;
	t_point	**point_map;

	i = 0;
	j = 0;
	point_map = global->map->point_map;
	while (i < global->map->total_rows)
	{
		while (j < global->map->total_cols)
		{
			if (point_map[i][j].type == '1')
			{
				mlx_put_image_to_window(global->mlx->mlx_ptr, global->mlx->win,
					global->wall_img->img_ptr, point_map[i][j].x * SPRITE_SIZE,
					point_map[i][j].y * SPRITE_SIZE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	paint_collec(t_global *global)
{	
	int		i;
	int		j;
	t_point	**point_map;

	i = 0;
	j = 0;
	point_map = global->map->point_map;
	while (i < global->map->total_rows)
	{
		while (j < global->map->total_cols)
		{
			if (point_map[i][j].type == 'C')
			{
				mlx_put_image_to_window(global->mlx->mlx_ptr, global->mlx->win,
					global->collec_img->img_ptr,
					point_map[i][j].x * SPRITE_SIZE,
					point_map[i][j].y * SPRITE_SIZE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	paint_exit(t_global *global)
{
	int		i;
	int		j;
	t_point	**point_map;

	i = 0;
	j = 0;
	point_map = global->map->point_map;
	while (i < global->map->total_rows)
	{
		while (j < global->map->total_cols)
		{
			if (point_map[i][j].type == 'E')
			{
				mlx_put_image_to_window(global->mlx->mlx_ptr, global->mlx->win,
					global->exit_c_img->img_ptr,
					point_map[i][j].x * SPRITE_SIZE,
					point_map[i][j].y * SPRITE_SIZE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	open_exit(t_global *global)
{
	int		i;
	int		j;
	t_point	**point_map;

	i = 0;
	j = 0;
	point_map = global->map->point_map;
	while (i < global->map->total_rows)
	{
		while (j < global->map->total_cols)
		{
			if (point_map[i][j].type == 'E')
			{
				mlx_put_image_to_window(global->mlx->mlx_ptr, global->mlx->win,
					global->exit_o_img->img_ptr,
					point_map[i][j].x * SPRITE_SIZE,
					point_map[i][j].y * SPRITE_SIZE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
