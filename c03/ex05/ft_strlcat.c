/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:06:32 by del-yaag          #+#    #+#             */
/*   Updated: 2022/09/03 15:55:53 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	d;
	int	l;

	d = ft_strlen(dest);
	l = ft_strlen(dest) + ft_strlen(src);
	i = 0;
	if (size == 0 || size < (unsigned) d)
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && (unsigned) d < size - 1)
	{
		dest[d] = src[i];
		d++;
		i++;
	}
	dest[d] = '\0';
	return (l);
}
