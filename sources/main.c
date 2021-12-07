/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:15:16 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/06 20:40:26 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_map map)
{
	map.cols = 0;
	map.lines = 0;
}

void	check_map_extension(char *file)
{
	char	*s;

	s = ft_strchr(file, '.');
	if (!s || ft_strncmp(s, ".ber", 5) != 0)
	{
		perror("Error. Map with wrong extension");
		exit (10);
	}
}

void	read_map(t_map map, char *file, char **lines)
{
	int	fd;
	int	line_n;
	int i;

	line_n = 1;
	*lines = NULL;
	init_map(map);
	fd = open(file, O_RDONLY);
	printf("file descriptor is %d\n", fd);
	if (fd < 0)
	{
		printf("Open failed\n");
	}
	while (line_n != 0)
	{
		line_n = get_next_line(fd, lines);
		map.lines++;
	}
	while (lines[0])
	{
		if (lines[0][map.cols] == '\0' || lines[0][map.cols] == '\n')
			break;
		map.cols++;
	}
	printf("Lines %d\n", map.lines);
	printf("columns %d\n", map.cols);
	i = 0;
	while (i < map.cols)
	{
		if (lines[0][i] != 1 || (lines[map.lines - 1][i] != 1))
			printf("Error - map not correct");
		i++;
	}
	i = 0;
	while (i < map.lines)
		{
		if (lines[i][0] != 1 || (lines[map.cols - 1][i] != 1))
			printf("Error - map not correct");
		i++;
	}
}

// void	check_map(char *argv, t_map map)
// {
// 	int		fd;

// 	map.map2d = (char **)malloc(sizeof(char *) * map.lines + 1);
// }

int	main(int argc, char **argv)
{
	t_map	map;
	char 		*line;

	map.lines = 0;
	if (argc == 2)
	{
		check_map_extension(argv[1]);
		read_map(map, argv[1], &line);
	}
	else
		ft_putstr_fd("Error. Wrong number of arguments.\n", 2);
	return (0);
}