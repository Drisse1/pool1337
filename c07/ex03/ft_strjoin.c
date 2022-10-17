/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:59:41 by del-yaag          #+#    #+#             */
/*   Updated: 2022/09/13 22:38:17 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		new_length;
	char	*new_string;
	int		i;

	if (size <= 0)
		return (NULL);
	i = 0;
	new_length = ft_strlen(sep) * (size - 1);
	while (++i < size)
		new_length += ft_strlen(strs[i]);
	new_length++;
	new_string = malloc(sizeof(char) * new_length);
	if (!(new_string))
		return (NULL);
	ft_strcpy(new_string, strs[0]);
	i = 0;
	while (++i < size)
	{
		ft_strcat(new_string, sep);
		ft_strcat(new_string, strs[i]);
	}
	return (new_string);
}

/*int main(void)
{
    //char strings[][20] = {{"hello"}, {"world"}, {"sir"}, {"awa"}, {"sir"}};
    
    char sep[] = " | ";
    
    char **strings = malloc(sizeof(char *) * 3);
    
    strings[0] = malloc(sizeof(char) * 6);
    ft_strcpy(strings[0], "hello");
    
    strings[1] = malloc(sizeof(char) * 6);
    ft_strcpy(strings[1], "world");
    
    strings[2] = malloc(sizeof(char) * 4);
    ft_strcpy(strings[2], "sir");
    
    char *new_string = ft_strjoin(3, strings, sep);
    printf("%s\n", new_string);
    return (0);
}*/
