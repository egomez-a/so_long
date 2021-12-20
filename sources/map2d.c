/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:02:41 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/20 19:09:17 by egomez-a         ###   ########.fr       */
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

void	check_map_borders(t_map map)
{
	int i;

	i = 0;
	while (i < map.cols)
	{
		if (map.map2d[0][i] != '1' || (map.map2d[map.lines - 1][i] != '1'))
		{
			printf("%d  -  %c %c\n", i, map.map2d[0][i], map.map2d[map.lines - 1][i]);
			perror("Error - horizontal borders not right\n");
			exit (11);
		}
		i++;
	}
	i = 0;
	while (i < map.lines)
		{
		if (map.map2d[i][0] != '1' || (map.map2d[i][map.cols - 1] != '1'))
		{
			perror("Error - vertical borders not right\n");
			exit (12);
		}
		i++;
	}
}

/* Check at least one element required */
void	check_map_elements(t_map map)
{
	int i;
	int j;
	
	map.elems.collectible = 0;
	map.elems.map_exit = 0;
	map.elems.initial_pos = 0;
	i = 0;
	while (i < map.lines)
	{
		j = 0;
		while (j < map.cols)
		{
			if (map.map2d[i][j] != '0' && map.map2d[i][j] != '1')
			{
				if (map.map2d[i][j] == 'E')
				{
					printf("EXIT it in  %d %d\n", i, j);
					map.elems.map_exit++;
				}	
				else if (map.map2d[i][j] == 'C')
				{
					printf("COLLECTIBLE in  %d %d\n", i, j);
					map.elems.collectible++;
				}
				else if (map.map2d[i][j] == 'P')
				{
					printf("INITIAL POSITION in  %d %d\n", i, j);
					map.hero_pos.y = i;
					map.hero_pos.x = j;
					map.elems.initial_pos++;
				}
				else
				{	
					perror("Error - non valid map element\n");
					return ;
				}
			}
			printf("Located wall or floor in  %d %d\n", i, j);
			printf("Map Exit = %d\n", map.elems.map_exit);
			printf("Initial position = %d\n", map.elems.initial_pos);
			printf("Collectionables = %d\n", map.elems.collectible);
			j++;
		}
		i++;
	}
	printf("Map Exit = %d\n", map.elems.map_exit);
	printf("Initial position = %d\n", map.elems.initial_pos);
	printf("Collectionables = %d\n", map.elems.collectible);
	if (map.elems.map_exit < 1)
	{
		perror("Error - missing map exit\n");
		exit (0);
	}
	if (map.elems.collectible < 1)
	{
		perror("Error - missing collectionables\n");
		exit (0);
	}
	if (map.elems.initial_pos < 1)
	{
		perror("Error - missing initial position\n");
		exit (0);
	}
}

/* Count number of lines */
int	map_lines(int fd)
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

/* Count number of columns and check if the map is rectangular */
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

/* Prints map for testing */
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
	// printf ("Columns are %d\n", j);
}

t_map	read_map(char *file)
{
	int		fd;
	int 	i;
	int 	gnl;
	t_map	map;

	fd = open(file, O_RDONLY);
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
			perror("Error: Map not rentangular\n");
			exit (0);
		}
		i++;
	}
	map.map2d[i] = NULL;
	close(fd);
	check_map_borders(map);
	check_map_elements(map);
	print_map(map);
	printf("El mapa es de %d x %d\n\n", map.cols, map.lines);
	return (map);
}