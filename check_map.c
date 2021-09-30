/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:10:39 by mmonereo          #+#    #+#             */
/*   Updated: 2021/09/29 16:20:52 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//checks if each line has same width
int check_line_width(t_list *head)
{
	int width;

	width = head->width;

	while( head != NULL )
	{	
		if (head->width != width)
			return(0);
		head = head->next;
	}
	return(1);	
}

// check if each line contains only valid characters
int check_elems(t_list *head)
{
	int i;
	char *line;
	
	while (head != NULL)
	{
		line = head->line;
		while (line[i])
		{		
			if ((!(ft_strchr(MAP_CHARS, line[i]))))
				return(0);
			else
				i++;
		}
		i = 0;
		head = head->next;	
	}
	return(1);
}

// checks if map is a rectangle by dividing height and width
int check_rectangle(t_list *head)
{
	int width;
	int height;

	width = head->width;
	height = ft_lstlast(head)->index + 1;
	if (width % height == 0 && width / height == 1)
		return(0);
	return(1);
}

// check first and last char of middle lines is 1
int check_closed_mid (t_list *head)
{	
	char *line;
	while (head != NULL)	
	{
		line = head->line;
		if (line[0] != '1')
			return(0);
		if (line[head->width - 1] != '1')
			return(0);
		head = head->next;	
	}
	return(1);
}

// check if map is closed with 1's
int check_closed (t_list *head)
{
	char *line;
	int i;

	i = 0;
	line = head->line;
	if(!(check_closed_mid(head)))
		return(0);
	while (line[i])			//check first line is full 1
	{
		if (line[i++] != '1')
			return(0);
	}
	head = ft_lstlast(head);
	line = head->line;
	i = 0;
	while (line[i])			//check last line is full 1
	{
		if (line[i++] != '1')
			return(0);
	}
	return(1);
}
// check if there is at least one of each CEP
int check_atleast_one(t_list *head)
{
	int c;
	int e;
	int p;
	char *line;
	int i;

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
		return(0);
	return(1);
}

// makes all the individual checks
int check_map (t_list *head)
{	
	if(!(check_line_width(head)))
		return(file_error(20));
	if(!(check_elems(head)))
		return(file_error(21));
	if(!(check_rectangle(head)))
		return(file_error(22));
	if(!(check_closed(head)))
		return(file_error(23));
	if(!(check_atleast_one(head)))
		return(file_error(24));
	printf("la lista esta en orden hermano\n");
	return(1);
}