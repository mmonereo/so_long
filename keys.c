/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:37:02 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/07 15:22:48 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(t_global *global, t_point *new)
{
	t_point	*old;

	old = global->player->current_position;
	if (new->type == '0')
	{
		global->player->prev_position = old;
		global->player->prev_position->type = '0';
		global->player->current_position = new;
		global->map->total_moves++;
		paint_player(global);
	}
	else if (new->type == 'C')
	{
		global->player->prev_position = old;
		global->player->prev_position->type = '0';
		global->player->current_position = new;
		global->map->collectibles--;
		global->map->total_moves++;
		if (global->map->collectibles == 0)
			open_exit(global);
		paint_player(global);
	}
	else
		move_player_2(global, new);
	return (1);
}

void	move_player_2(t_global *global, t_point *new)
{
	t_point	*old;

	old = global->player->current_position;
	if (new->type == '1')
	{
		global->player->prev_position = NULL;
	}
	else if (new->type == 'E' && global->map->collectibles == 0)
	{
		global->player->prev_position = old;
		global->player->prev_position->type = '0';
		paint_player(global);
		paint_exit(global);
		global->map->total_moves++;
		global->map->victory = 1;
		update_moves(global);
		printf("You Win!!\n");
	}
}

void	update_moves(t_global *global)
{
	char	*str;

	str = ft_itoa(global->map->total_moves);
	mlx_put_image_to_window(global->mlx->mlx_ptr,
		global->mlx->win, global->wall_img->img_ptr,
		(global->map->total_cols - 1) * SPRITE_SIZE, 0 * SPRITE_SIZE);
	mlx_string_put(global->mlx->mlx_ptr, global->mlx->win,
		SPRITE_SIZE * (global->map->total_cols - 1),
		SPRITE_SIZE * 0.5, -1, str);
	free(str);
	printf("Total Moves: %i\n", global->map->total_moves);
}

int	key_press(int keycode, t_global *global)
{
	if ((keycode == 126 || keycode == 13) && global->map->victory == 0)
		move_player(global, global->player->current_position->up);
	else if ((keycode == 125 || keycode == 1) && global->map->victory == 0)
		move_player(global, global->player->current_position->down);
	else if ((keycode == 123 || keycode == 0) && global->map->victory == 0)
	{
		global->player->right = 0;
		move_player(global, global->player->current_position->left);
	}
	else if ((keycode == 124 || keycode == 2) && global->map->victory == 0)
	{
		global->player->right = 1;
		move_player(global, global->player->current_position->right);
	}
	else if (keycode == 53)
		close_mlx(global);
	if (global->map->victory == 0)
		update_moves(global);
	return (1);
}
