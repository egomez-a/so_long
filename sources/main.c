/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:15:16 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/15 14:23:44 by egomez-a         ###   ########.fr       */
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

void	check_map_borders(t_map map, char **matrix)
{
	int i;

	i = 0;
	while (i < map.cols)
	{
		if (matrix[0][i] != 1 || (matrix[map.lines - 1][i] != 1))
			printf("Error - map not correct");
		i++;
	}
	i = 0;
	while (i < map.lines)
		{
		if (matrix[i][0] != 1 || (matrix[map.cols - 1][i] != 1))
			printf("Error - map not correct");
		i++;
	}
}

/* Count number of lines */
static int	map_lines(int fd)
{
	int 	mlines;
	int		char_buffer;
	char	c;

	mlines = 1;
	while (mlines > 0)
	{
		char_buffer = read(fd, &c, 1);
		if (char_buffer == 0)
			break ;
		if (char_buffer < 0)
		{
			perror("Opening file error - no lines");
			return (-1);
		}	
		if (c == '\n')
			mlines++;
	}
	close(fd);
	printf("Lines are %d\n", mlines);
	return (mlines);
}

int	check_columns(int i, t_map map)
{
	int columns;
	
	if (i == 0)
	{
		columns = (int)ft_strlen(map.map2d[i]);
		return (columns);
	}
	else if (i > 0)
	{
		if ((int)ft_strlen(map.map2d[i]) == map.cols)
		{
			columns = (int)ft_strlen(map.map2d[i]);
			return (columns);
		}
		else
		{	
			return (-1);
		}
	}
	return (0);
}

void	print_map(t_map map)
{
	int i;
	int j;
	
	i = 0;
	while (i < map.lines)
	{
		j = 0;
		while (map.map2d[i][j] != '\0')
		{
			printf("%c", map.map2d[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf ("Columns are %d\n", j);
}

void	read_map(t_map map, char *file)
{
	int		fd;
	int 	i;
	int 	gnl;

	fd = open(file, O_RDONLY);
	printf("file descriptor is %d\n", fd);
	check_fd(fd);
	map.lines = map_lines(fd);
	map.map2d = malloc(sizeof(char *) * (map.lines + 1));
	if (map.map2d == NULL)
		perror("Malloc error");
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < map.lines)
	{
		gnl = get_next_line(fd, &map.map2d[i]);
		map.cols = check_columns(i, map);
		if (map.cols == -1)
		{
			printf("Error: Map not rentangular\n");
			return ;
		}
		i++;
	}
	map.map2d[i] = NULL;
	close(fd);
	print_map(map);
	return ;
}

int	main(int argc, char **argv)
{
	t_map	map;

	map.lines = 0;
	if (argc == 2)
	{
		check_map_extension(argv[1]);
		read_map(map, argv[1]);
	}
	else
		ft_putstr_fd("Error. Wrong number of arguments.\n", 2);
	return (0);
}