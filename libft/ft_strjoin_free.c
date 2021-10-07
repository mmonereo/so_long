/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:04:46 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/07 11:49:44 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char			*joined;
	int				tlen;

	if (!s1 && !s2)
		return (0);
	tlen = (ft_strlen(s1) + ft_strlen(s2) + 1);
	joined = malloc(sizeof(char) * tlen);
	if (!joined)
		return (0);
	ft_memcpy(joined, s1, ft_strlen(s1));
	ft_memcpy(joined + ft_strlen(s1), s2, ft_strlen(s2));
	joined[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free ((void *) s1);
	return (joined);
}
