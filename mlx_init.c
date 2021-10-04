/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:21:26 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/04 16:21:32 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int close_mlx(t_global *global)
{	
	//free all shit
	mlx_destroy_window(global->mlx->mlx_ptr, global->mlx->win);
	exit(0);
	return(0);
}

void win_init(t_global *global)
{	
	int x;
	int y;

	x = global->map->total_cols * SPRITE_SIZE;
	y = global->map->total_rows * SPRITE_SIZE;
	global->mlx->win = mlx_new_window(global->mlx->mlx_ptr, x, y, "so_long");
	global->mlx->x_res = x;
	global->mlx->y_res = y;
}

t_img	*img_alloc(void)
{	
	t_img *img;
	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return(NULL);
	return(img);	
}

void initial_paint(t_global *global)
{
	player_initial_pos(global);
	paint_wall(global);
	paint_collec(global);
	paint_player(global);
	paint_exit(global);
}

int mlx_start(t_global *global)
{
	t_mini	*mlx;
	
	if(!(mlx = (t_mini *)malloc(sizeof(t_mini))))
		return(0);
	global->mlx = mlx;
	global->mlx->mlx_ptr = mlx_init();
	return(1);
}

int launch_game(t_global *global)
{
	if(!mlx_start(global))
		return(mlx_error(30));
	win_init(global);
	if(!get_all_sprites(global))
		return(mlx_error(31));
	initial_paint(global);
	if (global->map->victory == 0)
		mlx_key_hook(global->mlx->win, key_press, global);
	mlx_hook(global->mlx->win, 17, (1L<<5), close_mlx, global);
	mlx_loop(global->mlx->mlx_ptr);
	return(1);
}