/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:12:56 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/04 17:39:13 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int player_alloc(t_global *global)
{
	t_player *player;
	
	if(!(player = (t_player *)malloc(sizeof(t_player))))
		return(0);
	global->player = player;
	return(1);
}

void player_initial_pos(t_global *global)
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
			if (pointy[i][j].type == 'P')
			{
				global->player->current_position = &pointy[i][j];
				global->player->prev_position = NULL;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void paint_player(t_global *global)
{
	mlx_put_image_to_window(global->mlx->mlx_ptr, global->mlx->win, global->player->player_img->img_ptr, global->player->current_position->x * SPRITE_SIZE, global->player->current_position->y * SPRITE_SIZE);
	if (global->player->prev_position != NULL)
		mlx_put_image_to_window(global->mlx->mlx_ptr, global->mlx->win, global->floor_img->img_ptr, global->player->prev_position->x * SPRITE_SIZE, global->player->prev_position->y * SPRITE_SIZE);
}