/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:43:21 by hbouhach          #+#    #+#             */
/*   Updated: 2022/09/12 21:43:23 by hbouhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	copy_and_translate_map_row(int *cache_line, char *map_body_line,
		int width, char obstacle)
{
	int	x;

	x = 0;
	while (x < width)
	{
		if (map_body_line[x] == obstacle)
		{
			cache_line[x] = 0;
		}
		else
		{
			cache_line[x] = 1;
		}
		x++;
	}
}

void	copy_buffer(void *dest, void *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
}

int	min(int a, int b, int c)
{
	if (a < b && a < c)
	{
		return (a);
	}
	else if (b < c)
	{
		return (b);
	}
	else
	{
		return (c);
	}
}

void	zero_out_buffer(void *buffer, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		((char *)buffer)[i] = 0;
		i++;
	}
}

unsigned int	read_max(int fd, char *buffer, unsigned int max)
{
	unsigned int	bytes_read_count;
	unsigned int	total_read_bytes_count;

	bytes_read_count = 0;
	total_read_bytes_count = 0;
	while (max > total_read_bytes_count)
	{
		bytes_read_count = read(fd, buffer + total_read_bytes_count, 100);
		if (total_read_bytes_count + bytes_read_count == total_read_bytes_count)
			break ;
		total_read_bytes_count += bytes_read_count;
	}
	return (total_read_bytes_count);
}
