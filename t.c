int get_win_sprite(t_global *global)
{
	int x_sprite;
	int y_sprite;
	char *path = "sprites/you_win.xpm";
	if(!(global->win_img = img_alloc()))
		return(0);
	global->win_img->img_ptr = mlx_xpm_file_to_image(global->mlx->mlx_ptr, path, &x_sprite, &y_sprite);
	global->win_img->addr = mlx_get_data_addr(global->win_img->img_ptr, &global->win_img->bpp, &global->win_img->line_length, &global->win_img->endian);
	return(1);
}