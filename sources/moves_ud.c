/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:46:20 by egomez-a          #+#    #+#             */
/*   Updated: 2022/01/07 20:41:42 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	tile_change_up(t_game *game)
{
	mlx_clear_window(game->mlx, game->window.reference);
	game->map.map2d[game->hero.y][game->hero.x] = 'P';
	game->map.map2d[game->hero.y + 1][game->hero.x] = '0';
	game->moves++;
	paint_game(game);
}

void	hero_up(t_game *game)
{
	if ((game->map.elems.collect == 0)
		&& (game->map.map2d[game->hero.y][game->hero.x] == 'E'))
	{
		mlx_clear_window(game->mlx, game->window.reference);
		game->map.map2d[game->hero.y][game->hero.x] = 'P';
		game->map.map2d[game->hero.y + 1][game->hero.x] = '0';
		game->moves++;
		paint_game(game);
		game->endgame = 42;
		printf("GAME OVER with %d moves!", game->moves);
	}
	else if ((game->map.map2d[game->hero.y][game->hero.x] == '1')
		|| (game->map.map2d[game->hero.y][game->hero.x] == 'E'))
		game->hero.y += 1;
	else if (game->map.map2d[game->hero.y][game->hero.x] == '0')
		tile_change_up(game);
	else if (game->map.map2d[game->hero.y][game->hero.x] == 'C')
	{
		game->map.elems.collect--;
		tile_change_up(game);
	}
}

void	tile_change_down(t_game *game)
{
	mlx_clear_window(game->mlx, game->window.reference);
	game->map.map2d[game->hero.y][game->hero.x] = 'P';
	game->map.map2d[game->hero.y - 1][game->hero.x] = '0';
	game->moves++;
	paint_game(game);
}

void	hero_down(t_game *game)
{
	if ((game->map.elems.collect == 0)
		&& (game->map.map2d[game->hero.y][game->hero.x] == 'E'))
	{
		mlx_clear_window(game->mlx, game->window.reference);
		game->map.map2d[game->hero.y][game->hero.x] = 'P';
		game->map.map2d[game->hero.y - 1][game->hero.x] = '0';
		game->moves++;
		paint_game(game);
		game->endgame = 42;
		printf("GAME OVER with %d moves!", game->moves);
	}
	else if ((game->map.map2d[game->hero.y][game->hero.x] == '1')
		|| (game->map.map2d[game->hero.y][game->hero.x] == 'E'))
		game->hero.y -= 1;
	else if (game->map.map2d[game->hero.y][game->hero.x] == '0')
		tile_change_down(game);
	else if (game->map.map2d[game->hero.y][game->hero.x] == 'C')
	{
		game->map.elems.collect--;
		tile_change_down(game);
	}
}
