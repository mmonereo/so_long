/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:58:30 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/07 11:35:31 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*new;
	size_t		i;

	i = 0;
	new = malloc(sizeof(size) * nmemb);
	if (!new)
		return (NULL);
	while (i < size * nmemb)
	{
		new[i] = '\0';
		++i;
	}
	return ((void *)new);
}
