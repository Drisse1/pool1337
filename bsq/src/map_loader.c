/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:28:34 by hbouhach          #+#    #+#             */
/*   Updated: 2022/09/14 12:28:36 by hbouhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	read_map_header(t_map_info *map)
{
	char	header[10 + 3];
	int		i;

	i = 0;
	while (read(map->fd, &header[i], 1) && header[i] != '\n' && i + 1 < 13)
		i++;
	if (i < 4)
		return (-1);
	if (header[i] != '\n')
		return (-1);
	map->header_length = i;
	map->full = header[i - 1];
	map->obstacle = header[i - 2];
	map->empty = header[i - 3];
	map->y = ft_atoi(header, i - 3);
	map->no_obstacles = 1;
	if (!map->y)
		return (-1);
	return (1);
}

int	copy_and_alloc_row(t_map_info *map, char **previous_buffer, \
		char *init_buffer, int *current_size)
{
	map->first_row->buffer = malloc(*current_size + READ_LINE_CHUNK_SIZE + 1);
	if (!map->first_row->buffer)
		return (-1);
	copy_buffer(map->first_row->buffer, *previous_buffer, *current_size);
	if (*previous_buffer != init_buffer)
		free(*previous_buffer);
	return (1);
}

int	handle_large_first_line(t_map_info *map, char *previous_buffer,
		char *init_buffer, int current_size)
{
	int		read_bytes_count;
	int		i;
	char	*buffer;

	i = 0;
	while (i < READ_LINE_CHUNK_SIZE)
	{
		if (i == 0)
			if (copy_and_alloc_row(map, &previous_buffer, init_buffer,
					&current_size) == -1)
				return (-1);
		buffer = map->first_row->buffer + current_size;
		read_bytes_count = read(map->fd, &buffer[i], 1);
		if (!read_bytes_count && buffer[i - 1] != '\n')
			return (-1);
		if (buffer[i] == '\n')
			return ((buffer[i + 1] = '\0') + 1);
		if (++i == READ_LINE_CHUNK_SIZE)
		{
			i = 0;
			current_size += READ_LINE_CHUNK_SIZE;
			previous_buffer = map->first_row->buffer;
		}
	}
	return (-1);
}

int	get_first_line(t_map_info *map)
{
	int		i;
	int		read_bytes_count;
	char	init_buffer[INIT_FIRST_LINE_SIZE];

	i = 0;
	while (i < INIT_FIRST_LINE_SIZE)
	{
		read_bytes_count = read(map->fd, &init_buffer[i], 1);
		if (!read_bytes_count && init_buffer[i - 1] != '\n')
			return (-1);
		if (init_buffer[i] == '\n')
		{
			i++;
			map->first_row->buffer = malloc(i + 1);
			if (!map->first_row->buffer)
				return (-1);
			copy_buffer(map->first_row->buffer, init_buffer, i);
			map->first_row->buffer[i] = '\0';
			return (1);
		}
		i++;
	}
	return (handle_large_first_line(map, init_buffer, init_buffer,
			INIT_FIRST_LINE_SIZE));
}
