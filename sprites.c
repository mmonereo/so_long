/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:43:09 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/04 16:12:43 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_wall_sprite(t_global *global)
{
	int x_sprite;
	int y_sprite;
	char *path = "sprites/dungeon_floor.xpm";
	if(!(global->wall_img = img_alloc()))
		return(0);
	global->wall_img->img_ptr = mlx_xpm_file_to_image(global->mlx->mlx_ptr, path, &x_sprite, &y_sprite);
	global->wall_img->addr = mlx_get_data_addr(global->wall_img->img_ptr, &global->wall_img->bpp, &global->wall_img->line_length, &global->wall_img->endian);
	return(1);
}

int get_collec_sprite(t_global *global)
{
	int x_sprite;
	int y_sprite;
	char *path = "sprites/flask.xpm";
	if(!(global->collec_img = img_alloc()))
		return(0);
	global->collec_img->img_ptr = mlx_xpm_file_to_image(global->mlx->mlx_ptr, path, &x_sprite, &y_sprite);
	global->collec_img->addr = mlx_get_data_addr(global->collec_img->img_ptr, &global->collec_img->bpp, &global->collec_img->line_length, &global->collec_img->endian);
	return(1);
}

int get_player_sprite(t_global *global)
{
	int x_sprite;
	int y_sprite;
	char *path = "sprites/skell.xpm";
	if(!(player_alloc(global)))
		return(0);
	if(!(global->player->player_img = img_alloc()))
		return(0);
	global->player->player_img->img_ptr = mlx_xpm_file_to_image(global->mlx->mlx_ptr, path, &x_sprite, &y_sprite);
	global->player->player_img->addr = mlx_get_data_addr(global->player->player_img->img_ptr, &global->player->player_img->bpp, &global->player->player_img->line_length, &global->player->player_img->endian);
	return(1);
}

int get_floor_sprite(t_global *global)
{
	if(!(global->floor_img = img_alloc()))
		return(0);
	global->floor_img->img_ptr = mlx_new_image(global->mlx->mlx_ptr, SPRITE_SIZE, SPRITE_SIZE);
	global->floor_img->addr = mlx_get_data_addr(global->floor_img->img_ptr, &global->floor_img->bpp, &global->floor_img->line_length, &global->floor_img->endian);
	return(1);
}

int get_open_exit_sprite(t_global *global)
{
	int x_sprite;
	int y_sprite;
	char *path = "sprites/chest_open.xpm";
	if(!(global->exit_o_img = img_alloc()))
		return(0);
	global->exit_o_img->img_ptr = mlx_xpm_file_to_image(global->mlx->mlx_ptr, path, &x_sprite, &y_sprite);
	global->exit_o_img->addr = mlx_get_data_addr(global->exit_o_img->img_ptr, &global->exit_o_img->bpp, &global->exit_o_img->line_length, &global->exit_o_img->endian);
	return(1);
}

int get_closed_exit_sprite (t_global *global)
{
	int x_sprite;
	int y_sprite;
	char *path = "sprites/chest_closed.xpm";
	if(!(global->exit_c_img = img_alloc()))
		return(0);
	global->exit_c_img->img_ptr = mlx_xpm_file_to_image(global->mlx->mlx_ptr, path, &x_sprite, &y_sprite);
	global->exit_c_img->addr = mlx_get_data_addr(global->exit_c_img->img_ptr, &global->exit_c_img->bpp, &global->exit_c_img->line_length, &global->exit_c_img->endian);
	return(1);
}

int get_win_sprite(t_global *global)
{
	int x_sprite;
	int y_sprite;
	char *path = "sprites/you_won.xpm";
	if(!(global->win_img = img_alloc()))
		return(0);
	global->win_img->img_ptr = mlx_xpm_file_to_image(global->mlx->mlx_ptr, path, &x_sprite, &y_sprite);
	global->win_img->addr = mlx_get_data_addr(global->win_img->img_ptr, &global->win_img->bpp, &global->win_img->line_length, &global->win_img->endian);
	return(1);
}

int get_background_sprite(t_global *global)
{
	if(!(global->background_img = img_alloc()))
		return(0);
	global->background_img->img_ptr = mlx_new_image(global->mlx->mlx_ptr, global->mlx->x_res, global->mlx->y_res);
	global->background_img->addr = mlx_get_data_addr(global->background_img->img_ptr, &global->background_img->bpp, &global->background_img->line_length, &global->background_img->endian);
	return(1);
}

int get_all_sprites(t_global *global)
{
	if(!(get_wall_sprite(global)))
		return(0);
	if(!(get_collec_sprite(global)))
		return(0);
	if(!(get_floor_sprite(global)))
		return(0);
	if(!(get_player_sprite(global)))
		return(0);
	if(!(get_closed_exit_sprite(global)))
		return(0);
	if(!(get_open_exit_sprite(global)))
		return(0);
	if(!(get_win_sprite(global)))
		return(0);
	if(!(get_background_sprite(global)))
		return(0);
	return(1);
}