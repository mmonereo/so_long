/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:59:43 by mmonereo          #+#    #+#             */
/*   Updated: 2021/10/07 11:24:34 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	int	value;

	value = 0;
	if ((c >= 0 && c <= 127))
	{
		value = 1;
	}
	else
	{
		value = 0;
	}
	return (value);
}
