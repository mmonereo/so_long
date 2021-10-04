/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:05:37 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/04 16:20:48 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//checks longest row that needs to be allocated for map matrix
int check_max_row(t_list *head)		
{
	int max_len;
	t_list *tmp;

	max_len = head->width;
	tmp = head;

	while (head->next != NULL)
	{
		head = tmp->next;
		if(head->width > max_len)
			max_len = head->width;
		tmp = tmp->next;
	}
	return (max_len);
}

// gets map size info 
void	map_size (t_list *head, t_map *map)
{
	map->total_rows = ft_lstlast(head)->index + 1;
	map->total_cols = check_max_row(head);
}

t_map *alloc_map_struct(void)
{
	t_map *map;

	if(!(map = (t_map *)malloc(sizeof(t_map))))
		return(NULL);
	map->collectibles = 0;
	map->player_dup = 0;
	map->total_moves = 0;
	map->victory = 0;
	return (map);
}
