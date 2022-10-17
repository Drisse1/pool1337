/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:29:41 by del-yaag          #+#    #+#             */
/*   Updated: 2022/09/08 13:13:10 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb == 2147483647)
		return (1);
	while (i <= nb / i)
	{
		if (nb % i == 0)
		{
			return (0);
			break ;
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (ft_is_prime(nb) == 1)
		return nb;
	while(ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}

int main(void)
{
	printf("%d", ft_find_next_prime(8));
}
