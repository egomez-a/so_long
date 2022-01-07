/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:59:18 by egomez-a          #+#    #+#             */
/*   Updated: 2022/01/07 19:06:14 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_game *game)
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

int	key_press(int keynote, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if ((keynote == ESC) || (game->endgame == 42))
		close_game(game);
	else
	{
		game_move(keynote, game);
		if (game->endgame != 42)
			printf("Moves: %d, collectibless pending %d\n", game->moves,
				game->map.elems.collect);
	}
	return (0);
}

void	game_play(t_game *game)
{
	mlx_hook(game->window.reference, 2, 1L << 0, key_press, game);
	mlx_hook(game->window.reference, 17, 1L << 17, close_game, game);
	mlx_hook(game->window.reference, 9, 1L << 21, paint_game, game);
}
