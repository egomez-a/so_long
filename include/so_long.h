/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:16:42 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/13 13:31:20 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "./minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>	/* read */
# include <unistd.h>
# include <string.h>
# include <fcntl.h>		/* open */
# include "../libft/libft.h"

# define BUFFER_SIZE 1
# define M 64
# define A 97
# define W 119
# define D 100
# define S 115
# define ESC 65307

typedef struct s_map
{
	int		lines;
	int		cols;
	char	**map2d;
}				t_map;

int		main(int argc, char **argv);

/* get_next_line */
int	stvar_next_line(int ret, char **stvar, char **line);
int	get_next_line(int fd, char **line);
int	memclear(char **pointer);

/* check map */
void	check_map_extension(char *argv);
void	init_map(t_map map);
void	read_map(t_map map, char *file);

// void	check_map(char *argv, t_map map);

/* errors */
void	check_fd(int fd);

#endif