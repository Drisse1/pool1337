/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:11:10 by del-yaag          #+#    #+#             */
/*   Updated: 2022/08/31 20:04:49 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(void)
{
    char	a[] = "hello";
    char	b[5] = "";
    printf("size of dest; %d, %s\n", ft_strlcpy(b, a, 5), b);

    return (0);
}
