/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:39:00 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/07 12:29:20 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *argv)
{
	int		i;
	char	*ber;

	i = 0;
	ber = ft_substr(argv, (ft_strlen(argv) - 4), 4);
	if (!ft_memcmp(ber, ".ber", 4))
	{
		free(ber);
		return (1);
	}
	else
	{
		free(ber);
		return (file_error(25));
	}
}

// check if there is at least one of each CEP
int	check_atleast_one(t_list *head)
{
	int		c;
	int		e;
	int		p;
	char	*line;
	int		i;

	while (head != NULL)
	{	
		i = 0;
		line = head->line;
		while (line[i])
		{
			if (line[i] == 'C')
				c = 1;
			if (line[i] == 'E')
				e = 1;
			if (line[i] == 'P')
				p = 1;
			i++;
		}
		head = head->next;
	}
	if ((c != 1) || (e != 1) || (p != 1))
		return (0);
	return (1);
}

// makes all the individual checks
int	check_map(t_list *head)
{
	if (! (check_line_width(head)))
		return (file_error(20));
	if (! (check_elems(head)))
		return (file_error(21));
	if (! (check_rectangle(head)))
		return (file_error(22));
	if (! (check_closed(head)))
		return (file_error(23));
	if (! (check_atleast_one(head)))
		return (file_error(24));
	return (1);
}
