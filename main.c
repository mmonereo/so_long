/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:38:13 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/07 15:20:49 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	opener(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		return (file_error(26));
	}
	return (fd);
}

t_list	*get_lst(int fd)
{
	t_list	*lst;

	lst = load_lst(fd);
	if (!lst)
	{
		ft_lstclear(&lst);
		close(fd);
		return (0);
	}
	close(fd);
	if (!(check_map(lst)))
	{
		ft_lstclear(&lst);
		return (0);
	}
	return (lst);
}

t_map	*get_map(char **argv)
{
	int		fd;
	t_list	*lst;
	t_point	**point_map;
	t_map	*map;

	fd = opener(argv);
	if (!fd)
		return (NULL);
	lst = get_lst(fd);
	if (!lst)
		return (NULL);
	map = alloc_map_struct();
	if (!map)
	{
		ft_lstclear(&lst);
		return (NULL);
	}
	map_size(lst, map);
	point_map = fill_point_map(lst, map);
	ft_lstclear(&lst);
	return (map);
}

t_global	*start_global_struct(char **argv)
{
	t_global	*global;
	t_map		*map;

	map = get_map(argv);
	if (!map)
		return (NULL);
	global = (t_global *)malloc(sizeof(t_global));
	if (!global)
		return (NULL);
	global->map = map;
	return (global);
}

int	main(int argc, char **argv)
{
	t_global	*global;

	if (argc != 2 || !check_ber(argv[1]))
		return (-1);
	global = start_global_struct(argv);
	if (!global)
		return (-1);
	launch_game(global);
	return (0);
}
