/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:34:11 by mmonereo          #+#    #+#             */
/*   Updated: 2021/09/27 16:35:53 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_lstclear(t_list **lst)
{
	t_list *tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = tmp->next;
		if (tmp->line)
			free(tmp->line);
		free(tmp);
		tmp = NULL;
	}
	*lst = NULL;
}

t_list *new_lst (void)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	ft_memset(new, '\0', sizeof(t_list));
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

void print_lst (t_list *to_print)
{
	t_list *tmp;
	int		i;
	
	i = 0;
	tmp = to_print;
	while (to_print != NULL)
	{	
		printf("lst %i: %s\n", to_print->index, to_print->line);
		printf("ancho: %i\n", to_print->width);
		to_print = tmp->next;
		tmp = tmp->next;
		i++;
	}
}

// creates a list where each node has a line from file ,an index num and line len
t_list *load_lst(int fd)
{
	char		*line;
	int			i;
	t_list		*head;
	t_list		*new;
	
	head = NULL;
	i = 0;
	while (get_next_line(fd, &line))
	{
		new = new_lst();
		new->line = ft_strdup(line);
		new->width = ft_strlen(line);
		new->index = i;
		ft_lstadd_back(&head, new);
		i++;
		free(line);
	}
	new = new_lst();
	new->line = ft_strdup(line);
	new->width = ft_strlen(line);
	new->index = i;
	ft_lstadd_back(&head, new);
	i++;
	free(line);
	return(head);
}
