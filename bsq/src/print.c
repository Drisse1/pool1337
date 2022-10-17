/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:45:46 by hbouhach          #+#    #+#             */
/*   Updated: 2022/09/14 14:47:04 by hbouhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	no_obstacle_map_print(t_map_info *map)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	min;
	char			*current_row_in_map_body;

	if (map->y < map->x)
		min = map->y;
	else
		min = map->x;
	y = 0;
	while (y < map->y)
	{
		current_row_in_map_body = map->map_body + (y * (map->x + 1));
		x = 0;
		while (x < map->x)
		{
			if (x < min && y < min)
				write(1, &map->full, 1);
			else
				write(1, &current_row_in_map_body[x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	single_row_map_print(t_map_info *map)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	square_printed;
	char			*current_row_in_map_body;

	square_printed = 0;
	y = 0;
	while (y < map->y)
	{
		current_row_in_map_body = map->map_body + (y * (map->x + 1));
		x = 0;
		while (x < map->x)
		{
			if (!square_printed && current_row_in_map_body[x] == map->empty)
			{
				write(1, &map->full, 1);
				square_printed = 1;
			}
			else
				write(1, &current_row_in_map_body[x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	solved_map_print(t_map_info *map)
{
	unsigned int	y;
	unsigned int	x;
	char			*current_row_in_map_body;

	y = 0;
	while (y < map->y)
	{
		current_row_in_map_body = map->map_body + (y * (map->x + 1));
		x = 0;
		while (x < map->x)
		{
			if ((y >= (map->solution_coordinates->y
						- map->solution_coordinates->boxes)
					&& y < map->solution_coordinates->y)
				&& (x >= (map->solution_coordinates->x
						- map->solution_coordinates->boxes)
					&& x < map->solution_coordinates->x))
				write(1, &map->full, 1);
			else
				write(1, &current_row_in_map_body[x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
