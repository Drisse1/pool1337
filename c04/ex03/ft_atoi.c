/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:01:48 by del-yaag          #+#    #+#             */
/*   Updated: 2022/09/06 15:31:55 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}
int main()  
{  
    /*if (ac == 2)
        printf("%d", ft_atoi(av[1]));
    printf("\n");*/
    int val;  
    char string1[20] = " --- -+--+ 1234ab567"; 
    char string2[20] = " ---+--+1234ab567"; 
    val = ft_atoi(string1); 
    printf("Integer value = %d\n", val);
    val = atoi(string2);
    printf("Integer value = %d\n", val);
    return (0);  
}
