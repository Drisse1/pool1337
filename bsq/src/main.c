/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:43:15 by hbouhach          #+#    #+#             */
/*   Updated: 2022/09/12 21:56:26 by hbouhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

t_map_info	*load_map(char *map_filename, int fd)
{
	t_map_info	*map;

	if (!(fd > -1))
		return (NULL);
	map = malloc(sizeof(t_map_info));
	zero_out_buffer(map, sizeof(t_map_info));
	if (!map)
		return (NULL);
	map->first_row = malloc(sizeof(t_row_disciptor));
	map->fd = fd;
	map->filename = map_filename;
	if (!map->first_row || read_map_header(map) == -1 \
		|| get_first_line(map) == -1)
		return (NULL);
	map->x = ft_strlen(map->first_row->buffer) - 1;
	if (map->x == 0 || validate_map(map) == -1)
		return (NULL);
	return (map);
}

void	print_solution_map(t_map_info *map)
{
	if (map->y == 1 || map->x == 1)
	{
		single_row_map_print(map);
	}
	else if (map->no_obstacles)
	{
		no_obstacle_map_print(map);
	}
	else
	{
		if (map->solution_coordinates->boxes != 0)
			solved_map_print(map);
		else
		{
			map->check_edges = 1;
			print_solution_map(map);
		}
	}
}

/*void	print_cache_row(int *cache_line, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		printf("%d", cache_line[i]);
		i++;
	}
	printf("\n");
}*/

void	setup_cache(t_map_info *map, int current_y)
{
	int	i;

	if (current_y == 0)
		return ;
	if (current_y == 1)
	{
		copy_and_translate_map_row(map->cache, map->map_body, map->x, \
			map->obstacle);
		copy_and_translate_map_row(map->cache + map->x, \
			map->map_body + map->x + 1, map->x, map->obstacle);
	}
	else
	{
		i = 0;
		while ((unsigned int)i < map->x)
		{
			map->cache[i] = (map->cache + map->x)[i];
			i++;
		}
		copy_and_translate_map_row(map->cache + map->x, \
			map->map_body + (current_y * (map->x + 1)), map->x, map->obstacle);
	}
}

void	solve_map(t_map_info *map)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < map->y)
	{
		setup_cache(map, y);
		x = 0;
		while (x < map->x)
		{
			if ((map->map_body + (y * (map->x + 1)))[x] == map->empty && x != 0
				&& y != 0)
				(map->cache + map->x)[x] = min((map->cache + map->x)[x - 1],
						map->cache[x], map->cache[x - 1]) + 1;
			if (map->solution_coordinates->boxes < (map->cache + map->x)[x]
				&& x != 0 && y != 0)
			{
				map->solution_coordinates->boxes = (map->cache + map->x)[x];
				map->solution_coordinates->y = y + 1;
				map->solution_coordinates->x = x + 1;
			}
			x++;
		}
		y++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			handle_map_file(argv[i]);
			i++;
			if (i < argc)
				write(1, "\n", 1);
		}
	}
	else
	{
		handle_map_from_stdin();
	}
	return (0);
}
