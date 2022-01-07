/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:15:16 by egomez-a          #+#    #+#             */
/*   Updated: 2022/01/07 20:50:28 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_move(int keynote, t_game *game)
{
	if (keynote == W)
	{
		game->hero.y -= 1;
		hero_up(game);
	}
	else if (keynote == S)
	{
		game->hero.y += 1;
		hero_down(game);
	}
	else if (keynote == A)
	{
		game->hero.x -= 1;
		hero_left(game);
	}
	else if (keynote == D)
	{
		game->hero.x += 1;
		hero_right(game);
	}
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
			game.map.elems.collect = check_map_elements(&game.map);
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
