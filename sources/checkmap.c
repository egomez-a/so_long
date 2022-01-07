/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:07:58 by egomez-a          #+#    #+#             */
/*   Updated: 2022/01/07 20:17:50 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_extension(char *file)
{
	char	*s;

	s = ft_strchr(file, '.');
	if (!s || ft_strncmp(s, ".ber", 5) != 0)
		return (0);
	return (1);
}

void	check_map_borders(t_map map)
{
	int	i;

	i = 0;
	printf("Checkmap borders columns is %d\n", map.cols);
	while (i < map.cols)
	{
		if (map.map2d[0][i] != '1' || (map.map2d[map.lines - 1][i] != '1'))
		{
			perror("Error\n Horizontal borders not right\n");
			exit (11);
		}
		i++;
	}
	i = 0;
	printf("Checkmap borders lines is %d\n", map.lines);
	while (i < map.lines)
	{
		if (map.map2d[i][0] != '1' || (map.map2d[i][map.cols - 1] != '1'))
		{
			perror("Error\n Vertical borders not right\n");
			exit (12);
		}
		i++;
	}
}

/* Count number of columns and check if the map is rectangular */
int	check_columns(int i, t_map map)
{
	int	columns;

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

void	check_map_elements2(t_map *map, int i, int j)
{
	if (map->map2d[i][j] != '0' && map->map2d[i][j] != '1')
	{
		if (map->map2d[i][j] == 'E')
			map->elems.map_exit++;
		else if (map->map2d[i][j] == 'C')
			map->elems.collect++;
		else if (map->map2d[i][j] == 'P')
		{
			map->elems.hero.y = i;
			map->elems.hero.x = j;
			map->elems.init_pos++;
		}
		else
		{	
			perror("Error\n Non valid map element\n");
			exit (22);
		}
	}
}

/* Check at least one element required */
int	check_map_elements(t_map *map)
{
	int	i;
	int	j;

	map->elems.collect = 0;
	map->elems.map_exit = 0;
	map->elems.init_pos = 0;
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->cols)
		{
			check_map_elements2(map, i, j);
			j++;
		}
		i++;
	}
	check_map_elements_error(map->elems.map_exit, map->elems.collect,
		map->elems.init_pos);
	return (map->elems.collect);
}
