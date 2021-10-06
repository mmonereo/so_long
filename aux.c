/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:23:51 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/05 17:01:07 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void leaks_exit(void)
{
	system("leaks so_long");
}

int close_mlx(t_global *global)
{
	mlx_destroy_window(global->mlx->mlx_ptr, global->mlx->win);
	free_all(global);
	exit(0);
	return(0);
}

void free_all(t_global *global)
{	
	if (global->map->point_map)
		free_point_map(global->map->point_map);
	if (global->map)
		free(global->map);
	if (global->mlx)
		free(global->mlx);
	if (global->player->player_right_img)
		free(global->player->player_right_img);
	if (global->player->player_left_img)
		free(global->player->player_left_img);
	if (global->player)
		free(global->player);
	if (global->wall_img)
		free(global->wall_img);
	if (global->collec_img)
		free(global->collec_img);
	if (global->floor_img)
		free(global->floor_img);
	if (global->exit_o_img)
		free(global->exit_o_img);
	if (global->exit_c_img)
		free(global->exit_c_img);
	free(global);
}