/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:16:42 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/28 17:56:03 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>	/* read */
# include <unistd.h>
# include <string.h>
# include <fcntl.h>		/* open */
# include "../libft/libft.h"

# define BUFFER_SIZE 1
# define A 97		/* left */
# define W 119		/* up */
# define D 100		/* right */
# define S 115		/* down */
# define ESC 65307
# define ANIMATION_FRAMES 10

/* hero coordinates with an x and y */
typedef struct	s_hero
{
	int	x;
	int	y;
}				t_hero;

/* vector with an x and y */
typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

/* A pointer to the window and its size */
typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

/* The 4 values that define a color */
typedef struct s_color {
	int	r;
	int g;
	int b;
	int a;
}	t_color;

/* all info needed for an image */
typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

/* the program to create windows */
typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
}				t_program;

/* Map elements: collectibles, exit and initial position */
typedef struct s_ele
{
	int		collectible;
	int		map_exit;
	int		initial_pos;	
}				t_ele;

/* Map structure, with lines, columns, matrix and elements */
typedef struct s_map
{
	int		lines;
	int		cols;
	char	**map2d;
	t_ele	elems;
	t_hero	hero_pos;
}				t_map;

int		main(int argc, char **argv);

/* get_next_line */
int		stvar_next_line(int ret, char **stvar, char **line);
int		get_next_line(int fd, char **line);
int		memclear(char **pointer);

/* check map */
void	check_map_extension(char *argv);
void	init_map(t_map map);
t_map	read_map(char *file);
void	check_map_borders(t_map map);
void	check_map_elements(t_map map);
void	print_map(t_map map);
int		map_lines(int fd);
int		check_columns(int i, t_map map);

/* window creation */
void		open_window(t_map map);
t_window	ft_new_window(void *mlx, int widht, int height, char *name);
int 		ft_close ();

/* include sprites */
t_image ft_new_image(void* mlx, int width, int height);
t_image ft_new_sprite(void *mlx, char *path);

/* Hooks */
int	ft_input(int key, void *param);

/* errors */
void	check_fd(int fd);

#endif