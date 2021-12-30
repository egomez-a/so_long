/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:15:16 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/29 13:07:02 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int close_game(t_game *game)
{
	memclear(game->map.map2d);
	mlx_destroy_image(game->mlx, game->img.collect);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.hero);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_window(game->mlx, game->window.reference);
	free(game->mlx);
	exit(0);
}

void	draw_image(t_game *game, void *image, int x, int y)
{
	int		xx;
	int		yy;

	xx = x * 32;
	yy = y * 32;
	mlx_put_image_to_window(game->mlx, game->window.reference, image, xx, yy);
}

void	draw_hero(t_game *game, void *image, int x, int y)
{
	game->map.elems.hero.x = x;
	game->map.elems.hero.y = y;
	draw_image(game, image, x, y);
}

void	draw_exit(t_game *game, int x, int y)
{
	if (game->collects == 0)
	{
		mlx_destroy_image(game->mlx, game->img.exit);
		game->img.exit = mlx_xpm_file_to_image
			(game->mlx, "images/exit.xpm", &game->img.img_w, &game->img.img_h);
	}
	draw_image(game, game->img.exit, x, y);
}

int	paint_game(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->map.map2d[y])
	{
		x = 0;
		while (game->map.map2d[y][x])
		{
			if (game->map.map2d[y][x] == '1')
				draw_image(game, game->img.wall, x, y);
			else if (game->map.map2d[y][x] == '0')
				draw_image(game, game->img.floor, x, y);
			else if (game->map.map2d[y][x] == 'P')
				draw_hero(game, game->img.hero, x, y);
			else if (game->map.map2d[y][x] == 'C')
				draw_image(game, game->img.collect, x, y);
			else if (game->map.map2d[y][x] == 'E')
				draw_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

t_window	new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	/* This mlx function creates a returns a pointer
	to a new window with a given size and name */
	window.reference = mlx_new_window(mlx, widht, height, name);
	printf("puntero creacion window es %p\n", window.reference);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}

void		hero_up(t_game *game)
{
	if ((game->map.map2d[game->hero.y][game->hero.x] == '1')
		|| (game->map.map2d[game->hero.y][game->hero.x] == 'E'))
		game->hero.y += 1;
	else if(game->map.map2d[game->hero.y][game->hero.x] == '0')
	{
		mlx_clear_window(game->mlx, game->window.reference);
		game->map.map2d[game->hero.y][game->hero.x] = 'P';
		game->map.map2d[game->hero.y + 1][game->hero.x] = '0';
		game->moves++;
		paint_game(game);
	}
	else if(game->map.map2d[game->hero.y][game->hero.x] == 'C')
	{
		mlx_clear_window(game->mlx, game->window.reference);
		game->map.map2d[game->hero.y][game->hero.x] = 'P';
		game->map.map2d[game->hero.y + 1][game->hero.x] = '0';
		game->collects++;
		game->moves++;
		paint_game(game);
	}
}

void	game_move(int keynote, t_game *game)
{
	if (keynote == W)
	{
		game->hero.y -= 1;
		hero_up(game);
	}
}

int	key_press(int keynote, void *param)
{
	t_game *game = (t_game *)param;
	
	if(keynote == ESC)
		close_game(game);
	else if (game->endgame == 0)
	{
		game_move(keynote, game);
		printf("Moves: %d\n", game->moves);	
	}
	return (0);
}

void	game_play(t_game *game)
{
	mlx_key_hook(game->window.reference, &key_press, &game);
}

void	img_create(t_game *game)
{
	game->img.floor = mlx_xpm_file_to_image
		(game->mlx, "images/floor.xpm", &game->img.img_w, &game->img.img_h);
	game->img.wall = mlx_xpm_file_to_image
		(game->mlx, "images/wall.xpm", &game->img.img_w, &game->img.img_h);
	game->img.hero = mlx_xpm_file_to_image
		(game->mlx, "images/hero.xpm", &game->img.img_w, &game->img.img_h);
	game->img.collect = mlx_xpm_file_to_image
		(game->mlx, "images/collect.xpm", &game->img.img_w, &game->img.img_h);
	game->img.exit = mlx_xpm_file_to_image
		(game->mlx, "images/exit.xpm", &game->img.img_w, &game->img.img_h);
}

void	open_window(t_game *game)
{
	game->mlx = mlx_init();
	game->window = new_window(game->mlx, game->map.cols * 32, game->map.lines * 32, "Bienvenido al juego de so_long!");
	game->moves = 0;
	game->endgame = 0;
	img_create(game);
	paint_game(game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	game.map.lines = 0;
	if (argc == 2)
	{
		if (check_map_extension(argv[1]))
		{
			game.map = read_map(argv[1]);
			open_window(&game);
			game_play(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			printf("Error. Map with wrong extension");
			return (0);
		}
	}
	else
	{
		printf("Error. Wrong number of arguments.\n");
		exit(1);
	}
	return (0);
}