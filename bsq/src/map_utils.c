/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:49:32 by hbouhach          #+#    #+#             */
/*   Updated: 2022/09/14 12:49:37 by hbouhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	handle_map_file(char *map_filename)
{
	int			fd;
	t_map_info	*map;

	fd = open(map_filename, O_RDONLY);
	map = load_map(map_filename, fd);
	if (map)
	{
		if (!map->no_obstacles && map->y != 1)
		{
			map->solution_coordinates = malloc(sizeof(t_map_coordinates));
			map->cache = malloc(((map->x * 2) + 1) * sizeof(int));
			if (!map->cache || !map->solution_coordinates)
				return ;
			zero_out_buffer(map->solution_coordinates, \
							sizeof(t_map_coordinates));
			solve_map(map);
		}
		print_solution_map(map);
	}
	else
		write(2, "map error\n", 10);
	free_map(map);
}

void	handle_map_from_stdin(void)
{
	t_map_info	*map;

	map = load_map("(stdin)", 0);
	if (map)
	{
		if (!map->no_obstacles || map->y != 1)
		{
			map->solution_coordinates = malloc(sizeof(t_map_coordinates));
			map->cache = malloc(((map->x * 2) + 1) * sizeof(int));
			if (!map->cache || !map->solution_coordinates)
				return ;
			zero_out_buffer(map->solution_coordinates, \
							sizeof(t_map_coordinates));
			solve_map(map);
		}
		print_solution_map(map);
	}
	else
		write(2, "map error\n", 10);
	free_map(map);
}

int	validate_map_body(t_map_info *map, unsigned int map_size)
{
	unsigned int	i;

	i = 0;
	while (i < map_size)
	{
		if ((i % (map->x + 1)) == map->x)
		{
			if (map->map_body[i] != '\n')
				return (-1);
		}
		else
		{
			if (!is_printable_char(map->map_body[i])
				|| (map->map_body[i] != map->empty
					&& map->map_body[i] != map->obstacle))
				return (-1);
			if (map->no_obstacles && map->map_body[i] == map->obstacle)
				map->no_obstacles = 0;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_map_info *map)
{
	unsigned int	map_size;
	unsigned int	bytes_read_count;
	unsigned int	first_row_size;

	if ((map->empty != map->obstacle) && (map->full != map->obstacle)
		&& (map->empty != map->full) && is_printable_char(map->empty)
		&& is_printable_char(map->obstacle) && is_printable_char(map->full))
	{
		first_row_size = map->x + 1;
		map_size = (map->y * (map->x + 1));
		map->map_body = malloc(map_size + 100);
		if (!map->map_body)
			return (-1);
		copy_buffer(map->map_body, map->first_row->buffer, first_row_size);
		bytes_read_count = read_max(map->fd, map->map_body + first_row_size, \
							(map_size - first_row_size));
		if ((map_size - first_row_size) > bytes_read_count)
			return (-1);
		return (validate_map_body(map, map_size));
	}
	return (-1);
}

void	free_map(t_map_info *map)
{
	return ;
	if (map)
	{
		if (map->solution_coordinates)
			free(map->solution_coordinates);
		if (map->first_row)
		{
			if (map->first_row->buffer)
				free(map->first_row->buffer);
			free(map->first_row);
		}
		if (map->map_body)
			free(map->map_body);
		if (map->cache)
			free(map->cache);
		free(map);
	}
}
