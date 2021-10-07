/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:34:11 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/07 12:48:15 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

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

t_list	*new_lst(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
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

t_list	*load_lst(int fd)
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
	return (head);
}
