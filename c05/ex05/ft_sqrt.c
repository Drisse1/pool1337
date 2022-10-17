/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:05:34 by del-yaag          #+#    #+#             */
/*   Updated: 2022/09/08 13:12:01 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (nb);
	/*if (nb > 0)
	{*/
		while (i <= (nb / 2))
		{
			if (i * i == nb)
				return (i);
			else if (i >= 46341)
				return (0);
			i++;
		}
	//}
	return (0);
}

int main()
{
	printf("%d", ft_sqrt(16));
}