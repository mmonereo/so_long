int get_floor_sprite(t_global *global)
{
	if(!(global->backgroung_img = img_alloc()))
		return(0);
	global->backgroung_img->img_ptr = mlx_new_image(global->mlx->mlx_ptr, SPRITE_SIZE, SPRITE_SIZE);
	global->backgroung_img->addr = mlx_get_data_addr(global->backgroung_img->img_ptr, &global->backgroung_img->bpp, &global->backgroung_img->line_length, &global->backgroung_img->endian);
	return(1);
}