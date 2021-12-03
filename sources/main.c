/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:15:16 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/03 18:46:49 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_extension(char *argv)
{
	char *ext;

	ext = malloc(sizeof(char *));
	ext = ft_strnstr(argv, ".", 1);
	printf("%s\n", ext);
	if (strcmp(ext, "ber"))
	{
		ft_putstr_fd("Error. Map has not right extension.\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		check_map_extension(argv[1]);
	}
	else
		ft_putstr_fd("Error.\nWrong number of arguments.\n", 2);
	return (0);
}