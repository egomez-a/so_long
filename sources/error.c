/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:18:06 by egomez-a          #+#    #+#             */
/*   Updated: 2022/01/07 20:50:37 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_fd(int fd)
{
	if (fd < 0)
	{
		printf("Open failed\n");
		exit (0);
	}
}

void	check_columns_error(int columns)
{
	if (columns == -1)
	{
		perror("Error\nMap not rentangular\n");
		exit (0);
	}
}

void	check_map_elements_error(int m_exit, int collects, int i_pos)
{
	if (m_exit < 1)
	{
		perror("Error\n Missing map exit\n");
		exit (0);
	}
	if (collects < 1)
	{
		perror("Error\n Missing collectionables\n");
		exit (0);
	}
	if (i_pos < 1)
	{
		perror("Error\n Missing initial position\n");
		exit (0);
	}
}
