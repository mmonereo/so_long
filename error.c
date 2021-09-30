/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:55:36 by mmonereo          #+#    #+#             */
/*   Updated: 2021/09/29 17:57:13 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int file_error(int error)
{
	if (error == 20)
		printf("Error\nAll lines must have the same width\n");
	if (error == 21)
		printf("Error\nMap contains invalid characters\n");
	if (error == 22)
		printf("Error\nMap is not rectangular\n");
	if (error == 23)
		printf("Error\nMap is not closed\n");
	if (error == 24)
		printf("Error\nMap is missing C, E or P\n");
	if (error == 25)
		printf("Error\nMap File must use .ber extension\n");
	if (error == 26)
		printf("Error\nMap File not found\n");
	return(0);
}

int mlx_error(int error)
{	
	if (error == 30)
		printf("Error\nError during minilib init\n");
	if (error == 31)
		printf("Error\nError loading sprites\n");
	//free globaal shit
	return(0);
}