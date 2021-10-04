/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:37:02 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/04 16:24:49 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move_player (t_global *global, t_point *new)
{
	t_point *old = global->player->current_position;

	if (new->type == '0')
	{
		global->player->prev_position = old;
		global->player->prev_position->type = '0';
		global->player->current_position = new;
		paint_player(global);
	}
	else if (new->type == 'C')
	{
		global->player->prev_position = old;
		global->player->prev_position->type = '0';
		global->player->current_position = new;
		global->map->collectibles--;
		if (global->map->collectibles == 0)
			open_exit(global);
		paint_player(global);
	}
	else if (new->type == '1')
	{
		global->player->prev_position = NULL;
		return(1);
	}
	else if(new->type == 'E' && global->map->collectibles == 0)
	{	
		mlx_put_image_to_window(global->mlx->mlx_ptr, global->mlx->win, global->background_img->img_ptr, 0, 0);
		mlx_put_image_to_window(global->mlx->mlx_ptr, global->mlx->win, global->win_img->img_ptr, 2 * SPRITE_SIZE, 2 * SPRITE_SIZE);
	}
	return(1);
}

int key_press(int keycode, t_global *global)
{
	if (keycode == 126)
		move_player(global, global->player->current_position->up);
	else if (keycode == 125)
		move_player(global, global->player->current_position->down);
	else if (keycode == 123)
		move_player(global, global->player->current_position->left);
	else if (keycode == 124)
		move_player(global, global->player->current_position->right);
	else if (keycode == 53)
		close_mlx(global);
	printf("Total Moves: %i\n", ++global->map->total_moves);
	return(1);
}
