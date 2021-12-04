/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:15:16 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/04 18:35:39 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_extension(char *argv)
{
	char *s;

	s = ft_strchr(argv, '.');
	if (!s || ft_strncmp(s, ".ber", 5) != 0)
		printf("Error - not right extension");
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		check_map_extension(argv[1]);
	}
	else
		ft_putstr_fd("Error. Wrong number of arguments.\n", 2);
	return (0);
}