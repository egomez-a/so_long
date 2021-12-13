/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:16:05 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/13 13:29:45 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	getnextline(int fd, char **line)
{
	int		bufferbytes;
	char	buffer[1];
	int		i;
	char	*join;

	*line = malloc(1);
	if (!(*line) || (!line))
		return (-1);
	bufferbytes = read(fd, buffer, 1);
	while (bufferbytes > 0)
	{
		if (buffer[0] == '\0' || buffer[0] == '\n')
			break; 
		i = 0;
		while ((*line)[i])
			i++;
		join = malloc(i + 2);
		if (join == 0)
			return (-1); 
		i = 0;
		while ((*line)[i] != '\0')
		{
			join[i] = (*line)[i];
			i++;
		}	
		join[i++] = buffer[0];
		join[i++] = '\0';
		free (*line);
		*line = join; 
	}
	return (bufferbytes);
}

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
	while (!ft_strchr(stvar, '\n') && ((ret = read(fd, buf, BUFFER_SIZE)) > 0))
	{
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
