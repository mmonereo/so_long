/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:11:01 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/07 14:27:54 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

int	get_open_exit_sprite(t_global *global)
{
	int		x_sprite;
	int		y_sprite;
	char	*path;

	path = "sprites/chest_open.xpm";
	global->exit_o_img = img_alloc();
	if (!global->exit_o_img)
		return (0);
	global->exit_o_img->img_ptr = mlx_xpm_file_to_image
		(global->mlx->mlx_ptr, path, &x_sprite, &y_sprite);
	global->exit_o_img->addr = mlx_get_data_addr
		(global->exit_o_img->img_ptr, &global->exit_o_img->bpp,
			&global->exit_o_img->line_length, &global->exit_o_img->endian);
	return (1);
}

int	get_closed_exit_sprite(t_global *global)
{
	int		x_sprite;
	int		y_sprite;
	char	*path;

	path = "sprites/chest_closed.xpm";
	global->exit_c_img = img_alloc();
	if (!global->exit_c_img)
		return (0);
	global->exit_c_img->img_ptr = mlx_xpm_file_to_image
		(global->mlx->mlx_ptr, path, &x_sprite, &y_sprite);
	global->exit_c_img->addr = mlx_get_data_addr
		(global->exit_c_img->img_ptr, &global->exit_c_img->bpp,
			&global->exit_c_img->line_length, &global->exit_c_img->endian);
	return (1);
}

t_img	*img_alloc(void)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	return (img);
}

int	get_all_sprites(t_global *global)
{
	if (!(get_wall_sprite(global)))
		return (0);
	if (!(get_collec_sprite(global)))
		return (0);
	if (!(get_floor_sprite(global)))
		return (0);
	if (!(get_player_right_sprite(global)))
		return (0);
	if (!(get_player_left_sprite(global)))
		return (0);
	if (!(get_closed_exit_sprite(global)))
		return (0);
	if (!(get_open_exit_sprite(global)))
		return (0);
	return (1);
}
