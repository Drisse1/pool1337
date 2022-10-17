/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:48:32 by hbouhach          #+#    #+#             */
/*   Updated: 2022/09/14 14:48:35 by hbouhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str, int limit)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9' && (limit != FT_ATOI_NO_LIMIT
			|| i < limit))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

int	is_printable_char(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

int	ft_get_char(int fd)
{
	char	c;

	return (read(fd, &c, 1));
}
