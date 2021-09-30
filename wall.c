/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:46:15 by mmonereo          #+#    #+#             */
/*   Updated: 2021/09/29 17:31:06 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void paint_wall(t_global *global)
{	
	int i;
	int j;
	t_point **pointy;
	
	i = 0;
	j = 0;
	pointy = global->map->point_map;
	while (i < global->map->total_rows)
	{	
		while (j < global->map->total_cols)
		{	
			if (pointy[i][j].type == '1')
			{
				mlx_put_image_to_window(global->mlx->mlx_ptr, global->mlx->win, global->wall_img->img_ptr, pointy[i][j].x * SPRITE_SIZE, pointy[i][j].y * SPRITE_SIZE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void paint_collec(t_global *global)
{	
	int i;
	int j;
	t_point **pointy;
	
	i = 0;
	j = 0;
	pointy = global->map->point_map;
	while (i < global->map->total_rows)
	{	
		while (j < global->map->total_cols)
		{	
			if (pointy[i][j].type == 'C')
			{
				mlx_put_image_to_window(global->mlx->mlx_ptr, global->mlx->win, global->collec_img->img_ptr, pointy[i][j].x * SPRITE_SIZE, pointy[i][j].y * SPRITE_SIZE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void paint_exit(t_global *global)
{	
	int i;
	int j;
	t_point **pointy;
	
	i = 0;
	j = 0;
	pointy = global->map->point_map;
	while (i < global->map->total_rows)
	{	
		while (j < global->map->total_cols)
		{	
			if (pointy[i][j].type == 'E')
			{
				mlx_put_image_to_window(global->mlx->mlx_ptr, global->mlx->win, global->exit_c_img->img_ptr, pointy[i][j].x * SPRITE_SIZE, pointy[i][j].y * SPRITE_SIZE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void open_exit(t_global *global)
{	
	int i;
	int j;
	t_point **pointy;
	
	i = 0;
	j = 0;
	pointy = global->map->point_map;
	while (i < global->map->total_rows)
	{	
		while (j < global->map->total_cols)
		{	
			if (pointy[i][j].type == 'E')
			{
				mlx_put_image_to_window(global->mlx->mlx_ptr, global->mlx->win, global->exit_o_img->img_ptr, pointy[i][j].x * SPRITE_SIZE, pointy[i][j].y * SPRITE_SIZE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

