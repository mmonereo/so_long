/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:38:13 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/04 16:19:09 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void leaks_exit(void)
{
	system("leaks so_long");
}

int opener(char **argv)
{
	int fd;

	if((fd = open(argv[1], O_RDONLY)) < 0)
	{
		return(file_error(26));
	}
	return(fd);
}

// loads lst from file, closes it and checks if it is valid
t_list *get_lst (int fd)
{
	t_list *lst;
	
	if (!(lst = load_lst(fd)))
	{
		ft_lstclear(&lst);
		close(fd);
		return(0);
	}
	close(fd);
	if (!(check_map(lst)))
	{
		ft_lstclear(&lst);
		return(0);
	}
	return(lst);
}

//get points map from file through lst
t_map *get_map (char **argv)
{
	int fd;
	t_list *lst;
	t_point **point_map;
	t_map	*map;

	if (!(fd = opener(argv)))
		return (NULL);
	if (!(lst = get_lst(fd)))
		return(NULL);
	if (!(map = alloc_map_struct()))
	{
		ft_lstclear(&lst);
		return(NULL);
	}
	map_size(lst, map);
	point_map = fill_point_map(lst, map);
	ft_lstclear(&lst);
	return(map);
}

t_global *start_global_struct (char **argv)
{
	t_global *global;
	t_map	*map;

	if(!(map = get_map(argv)))
		return(NULL);
	if(!(global = (t_global *)malloc(sizeof(t_global))))
		return(NULL);
	printf("TOTAL COL: %i\n", map->total_cols);
	printf("TOTAL ROW: %i\n", map->total_rows);
	global->map = map;
	/* print_points(map->point_map);
	free_point_map(map->point_map); */
	return(global);
}

int check_ber (char *argv)
{
	int i;
	char *ber;

	i = 0;
	ber = ft_substr(argv, (ft_strlen(argv) - 4), 4);
	if (!ft_memcmp(ber, ".ber", 4))
	{
		free(ber);
		return(1);
	}
	else 
	{
		free(ber);
		return(file_error(25));
	}	
}

int main (int argc, char **argv)
{
	t_global *global;
	
	atexit(leaks_exit);
	if (argc != 2 || !check_ber(argv[1]))
		return(-1);
	if(!(global = start_global_struct(argv)))
		return(-1);
	launch_game(global);
	return(0);
}


