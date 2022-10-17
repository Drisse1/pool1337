/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:37:48 by del-yaag          #+#    #+#             */
/*   Updated: 2022/08/31 19:05:37 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	main(void)
{
    char idk[10] = {[0 ... 8] = 'B'};
	char lol[10];
	//ft_strncpy(lol, "AAAAAAAAAAAAAAA", 10);
	strncpy(lol, "AAAAAAAAAAAAAAA", 10);
	printf("%s\n", lol);
    return 0;
}
