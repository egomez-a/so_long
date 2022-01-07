/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:16:05 by egomez-a          #+#    #+#             */
/*   Updated: 2022/01/07 19:00:11 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	memclear(char **pointer)
{
	if (pointer)
	{
		if (*pointer)
		{
			free(*pointer);
			*pointer = NULL;
			return (1);
		}
	}
	return (0);
}

int	stvar_next_line(int ret, char **stvar, char **line)
{
	char	*temp2;

	if (ret == 0)
	{
		temp2 = ft_substr(*stvar, ft_strlen(*line), ft_strlen(*stvar));
		memclear(stvar);
		*stvar = temp2;
		memclear(stvar);
		return (0);
	}
	else
	{
		temp2 = ft_substr(*stvar, ft_strlen(*line) + 1, ft_strlen(*stvar));
		memclear(stvar);
		*stvar = temp2;
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	*stvar;
	char		buf[BUFFER_SIZE + 1];
	char		*temp1;

	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!stvar)
		stvar = ft_strdup("");
	while (!ft_strchr(stvar, '\n') && (ret > 0))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		temp1 = ft_strjoin(stvar, buf);
		memclear(&stvar);
		stvar = temp1;
	}
	if (ret == 0)
		*line = ft_strdup(stvar);
	else if (ret > 0)
		*line = ft_substr(stvar, 0, (ft_strchr(stvar, '\n') - stvar));
	else
		return (-1 * memclear(&stvar));
	return (stvar_next_line(ret, &stvar, line));
}
