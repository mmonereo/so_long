/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:02:10 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/07 11:30:06 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*x;

	x = (unsigned char *)s;
	while (n--)
	{
		if (*x++ == (unsigned char)c)
		{
			return ((unsigned char *)(x - 1));
		}
	}
	return (NULL);
}
