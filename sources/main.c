/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:15:16 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/10 10:59:16 by egomez-a         ###   ########.fr       */
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

// void	check_map_content(t_map map, char **matrix)
// {
	
// }

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
	int		char_counter;
	char	c;
	
	mlines = 1;
	while (mlines > 0)
	{
		char_counter = read(fd, &c, 1);
		if (char_counter == 0)
			break ;
		if (char_counter < 0)
		{
			perror("Opening file error - no lines");
			return (-1);
		}	
		if (char_counter == '\n')
			mlines++;
	}
	close(fd);
	printf("Lines are %d\n", mlines);
	return (mlines);
}

static int	map_columns(t_map map)
{
	int mcolumns;
	
	mcolumns = 0;
	while (map.map2d[0])
	{
		if (map.map2d[0][map.cols] == '\0' || map.map2d[0][map.cols] == '\n')
			break;
		mcolumns++;
	}
	printf("columns %d\n", map.cols);
	return (mcolumns);
}

void	read_map(t_map map, char **argv)
{
	int		fd;
	int 	i;
	int 	j;

	fd = open(argv[1], O_RDONLY);
	printf("file descriptor is %d\n", fd);
	check_fd(fd);
	map.lines = map_lines(fd);
	map.map2d = malloc(sizeof(char *) * map.lines + 1);
	if (map.map2d == NULL)
		perror("Malloc error");
	map.cols = map_columns(map);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &map.map2d[i++]))
		;
	map.map2d[i] = NULL;
	i = 0;
	while (map.map2d[i])
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
	close(fd);
	return ;
}

int	main(int argc, char **argv)
{
	t_map	map;

	map.lines = 0;
	if (argc == 2)
	{
		check_map_extension(argv[1]);
		read_map(map, &argv[1]);
	}
	else
		ft_putstr_fd("Error. Wrong number of arguments.\n", 2);
	return (0);
}