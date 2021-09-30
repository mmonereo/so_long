/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:47:46 by mmonereo          #+#    #+#             */
/*   Updated: 2021/09/29 09:44:54 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		has_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*get_output(char *str)
{
	char	*output;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(output = malloc(sizeof(char) * (i + 1))))
		return (0);
	while (str[j] && str[j] != '\n')
	{
		output[j] = str[j];
		j++;
	}
	output[j] = '\0';
	return (output);
}

static char	*get_remain(char *str)
{
	int		i;
	char	*remain;
	int		j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		++i;
	}
	if (!str[i])
	{
		free(str);
		return (0);
	}
	if (!(remain = malloc(sizeof(char) * (ft_strlen(str) - i + 1))))
		return (0);
	while (str[i])
	{
		remain[j++] = str[++i];
	}
	remain[j] = '\0';
	free(str);
	return (remain);
}

int		get_next_line(const int fd, char **line)
{
	int			reader;
	char		*buf;
	char static	*text;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while (has_nl(text) == 0 && reader != 0)
	{
		if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (-1);
		if ((reader = read(fd, buf, BUFFER_SIZE)) == -1)
			{
				free(buf);
				return(-1);
			}
		buf[reader] = '\0';
		text = ft_strjoin_free(text, buf);
		free(buf);
	}
	*line = get_output(text);
	text = get_remain(text);
	if (reader == 0)
		return (0);
	return (1);
}

