/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:16:42 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/29 07:26:22 by egomez-a         ###   ########.fr       */
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

/* vector with an x and y */
/* 0,0 is the top left corner */
/* lines are x, move from 0 down, columns are y, move from 0 right */
typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_hero
{
	int	x;
	int	y;
}				t_hero;

/* A pointer to the window and its size */
typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

/* Map elements: collectibles, exit and initial position */
typedef struct s_ele
{
	int			collectible;
	int			map_exit;
	int			initial_pos;
	t_vector	hero;	
}				t_ele;

/* Map structure, with lines, columns, matrix and elements */
typedef struct s_map
{
	int		lines;
	int		cols;
	char	**map2d;
	t_ele	elems;
}				t_map;

typedef struct s_image
{
	void	*floor;
	void	*wall;
	void	*hero;
	void	*collect;
	void	*exit;
	int		img_w;
	int		img_h;
}				t_image;

/* All information for the game to run */
/* sprite positions are pixels, as we use 32 x 32 images, need adjustment */
typedef struct s_game
{
	void		*mlx;
	t_window	window;
	t_vector	position;
	t_vector	hero;
	t_map		map;
	t_image		img;
	int 		moves;
	int 		collects;
	int			endgame;
}				t_game;

int		main(int argc, char **argv);

/* get_next_line */
int		stvar_next_line(int ret, char **stvar, char **line);
int		get_next_line(int fd, char **line);
int		memclear(char **pointer);

/* check map */
int		check_map_extension(char *argv);
void	init_map(t_map map);
t_map	read_map(char *file);
void	check_map_borders(t_map map);
void	check_map_elements(t_map map);
void	print_map(t_map map);
int		map_lines(int fd);
int		check_columns(int i, t_map map);

/* window creation */
void		open_window(t_game *game);
int			paint_game(t_game *game);
t_window	new_window(void *mlx, int widht, int height, char *name);
int 		close_game(t_game *game);

/* draw elements */
void		draw_exit(t_game *game, int x, int y);
void		draw_hero(t_game *game, void *image, int x, int y);
void		draw_image(t_game *game, void *image, int x, int y);

/* Hooks */
void		game_play(t_game *game);
int			key_press(int keynote, t_game *game);

/* moves */
void		game_move(int keynote, t_game *game);
void		hero_up(t_game *game);
// void		hero_down(t_game *game);
// void		hero_left(t_game *game);
// void		hero_right(t_game *game);

/* errors */
void	check_fd(int fd);

#endif