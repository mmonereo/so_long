/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:10:36 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/05 17:26:12 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFO_H
 #define MAP_INFO_H

#include "libft/libft.h"
#include "mlx/mlx.h"
#include <fcntl.h>
#include <stdio.h>


#define MAP_CHARS		"012CEP"
#define SPRITE_SIZE		32

	typedef struct	s_lst			//list info struct
	{
		char			*line;
		int				width;
		int				index;
		struct	s_lst	*next;
	}					t_list;

	typedef struct		s_point		//struct with info from each point of the map
	{	
		char			type;
		int				x;
		int				y;
		struct s_point	*up;
		struct s_point	*down;
		struct s_point	*left;
		struct s_point	*right;
	}					t_point;

	typedef struct  s_img			//mlx img struct
	{
		void		*img_ptr;
		char		*addr;
		int			bpp;
		int			line_length;
		int			endian;
		int 		x_size;
		int			y_size;
	}				t_img;

	typedef struct  s_mini			//mlx general struct 
	{
		void		*mlx_ptr;
		void		*win;
		int			x_res;
		int			y_res;
	}				t_mini;

	typedef struct s_map
	{
		t_point	**point_map;
		int		total_rows;
		int		total_cols;
		int		collectibles;
		int		player_dup;
		int		total_moves;
		int		victory;
	}			t_map;

	typedef struct s_player
	{
		t_point	*current_position;
		t_point	*prev_position;
		int 	right;
		t_img	*player_right_img;
		t_img	*player_left_img;
	}			t_player;
	
	typedef struct s_global
	{
		t_map		*map;
		t_mini		*mlx;
		t_player	*player;
		t_img		*wall_img;
		t_img		*collec_img;
		t_img		*floor_img;
		t_img		*exit_o_img;
		t_img		*exit_c_img;
		t_img		*win_img;
		t_img		*background_img;
	}	t_global;

	//MAIN
	int			opener(char **argv);
	t_list		*get_lst (int fd);
	t_map		*get_map (char **argv);
	t_global	*start_global_struct (char **argv);

	//LST
	t_list	*new_lst		(void);
	t_list	*ft_lstlast		(t_list *lst);
	void	ft_lstadd_back	(t_list **lst, t_list *new);
	t_list	*load_lst		(int fd);
	void	ft_lstclear     (t_list **lst);


	//CHECK MAP
	int		check_line_width	(t_list *head);
	int		check_rectangle		(t_list *head);
	int		check_map			(t_list *head);
	int		check_closed		(t_list *head);
	int		check_closed_mid	(t_list *head);
	int		check_elems			(t_list *head);
	int		check_atleast_one	(t_list *head);
	int		check_ber			(char *argv);
	
	//MAP
	void	map_size 			(t_list *head, t_map *map);
	int		check_max_row		(t_list *first);
	t_map	*alloc_map_struct	(void);

	//POINT MAP
	t_point	**create_point_map	(t_map *map);
	t_point **fill_point_map	(t_list *head, t_map *map);
	void	fill_neighbors		(t_map *map, t_point **point_map, int i, int j);
	int		free_point_map		(t_point **point_map);
	void	count_items			(char item, t_map *map, int i, int j);
	
	
	//MLX START
	int		launch_game		(t_global *global);
	int		mlx_start		(t_global *global);
	void	win_init		(t_global *global);
	int		close_mlx		(t_global *global);
	void	initial_paint	(t_global *global);

	//SPRITES
	int	get_wall_sprite			(t_global *global);
	int	get_collec_sprite		(t_global *global);	
	int	get_floor_sprite		(t_global *global);
	int	get_player_sprite		(t_global *global);
	int get_player_left_sprite	(t_global *global);
	int get_player_right_sprite	(t_global *global);
	int get_closed_exit_sprite	(t_global *global);
	int get_open_exit_sprite	(t_global *global);
	int	get_all_sprites			(t_global *global);
	t_img	*img_alloc			(void);
	
	//WALL
	
	void	paint_floor		(t_global *global);
	void	paint_wall		(t_global *global);
	void	paint_collec	(t_global *global);
	void	paint_exit		(t_global *global);
	void	open_exit		(t_global *global);
	
	//PLAYER
	int		player_alloc		(t_global *global);
	void	player_initial_pos	(t_global *global);
	void	paint_player		(t_global *global);

	//KEYS
	int move_player				(t_global *global, t_point *new);
	void move_player_2			(t_global *global, t_point *new);
	int key_press				(int keycode, t_global *globlal);
	void update_moves			(t_global *global);

	// ERROR
	int file_error			(int error);
	int mlx_error			(int error, t_global *global);

	//AUX
	void leaks_exit		(void);
	int close_mlx		(t_global *global);
	void free_all		(t_global *global);

#endif
