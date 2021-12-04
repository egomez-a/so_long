/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:15:16 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/04 20:07:38 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_extension(char *argv)
{
	char *s;

	s = ft_strchr(argv, '.');
	if (!s || ft_strncmp(s, ".ber", 5) != 0)
	{
		perror("Error. Map with wrong extension");
		exit (10);
	}
}

void	read_map(t_map map, char **argv,  char **line)
{
	int fd;
	int gnl;
	
	gnl = 1;
	*line = NULL;
	init_map(map);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Open failed");
		free(map);
	}
	while (gnl != 0)
	{
		gnl = 
	}
}

void	init_map(t_map map)
{
	map.col = 0;
	map.lines = 0;
}

void	check_map(char *argv, t_map map)
{
	int		fd;
	t_map	map;

	

	map.map2d = (char **)malloc(sizeof(char *) * map.lines + 1);
	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		check_map_extension(argv[1]);
		check_map(argv[1]);
	}
	else
		ft_putstr_fd("Error. Wrong number of arguments.\n", 2);
	return (0);
}