/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:43:09 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/05 17:18:21 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_wall_sprite(t_global *global)
{
	int x_sprite;
	int y_sprite;
	char *path;
	
	path = "sprites/dungeon_floor.xpm";
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
	char *path; 
	
	path = "sprites/flask.xpm";
	if(!(global->collec_img = img_alloc()))
		return(0);
	global->collec_img->img_ptr = mlx_xpm_file_to_image(global->mlx->mlx_ptr, path, &x_sprite, &y_sprite);
	global->collec_img->addr = mlx_get_data_addr(global->collec_img->img_ptr, &global->collec_img->bpp, &global->collec_img->line_length, &global->collec_img->endian);
	return(1);
}

int get_player_right_sprite(t_global *global)
{
	int x_sprite;
	int y_sprite;
	char *path; 
	
	path = "sprites/skell.xpm";
	if(!(player_alloc(global)))
		return(0);
	if(!(global->player->player_right_img = img_alloc()))
		return(0);
	global->player->player_right_img->img_ptr = mlx_xpm_file_to_image(global->mlx->mlx_ptr, path, &x_sprite, &y_sprite);
	global->player->player_right_img->addr = mlx_get_data_addr(global->player->player_right_img->img_ptr, &global->player->player_right_img->bpp, &global->player->player_right_img->line_length, &global->player->player_right_img->endian);
	return(1);
}

int get_player_left_sprite(t_global *global)
{
	int x_sprite;
	int y_sprite;
	char *path; 
	
	path = "sprites/skell_left.xpm";
	if(!(global->player->player_left_img = img_alloc()))
		return(0);
	global->player->player_left_img->img_ptr = mlx_xpm_file_to_image(global->mlx->mlx_ptr, path, &x_sprite, &y_sprite);
	global->player->player_left_img->addr = mlx_get_data_addr(global->player->player_left_img->img_ptr, &global->player->player_left_img->bpp, &global->player->player_left_img->line_length, &global->player->player_left_img->endian);
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