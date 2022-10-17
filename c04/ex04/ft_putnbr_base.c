/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:18:44 by del-yaag          #+#    #+#             */
/*   Updated: 2022/09/06 17:17:44 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_verify(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+'
			|| base[i] == 127 || base[i] <= 32)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;

	nb = nbr;
	if (ft_verify(base) == 0)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb < ft_strlen(base))
	{
		ft_putchar(base[nb]);
		return ;
	}
	else
	{
		ft_putnbr_base((nb / ft_strlen(base)), base);
		ft_putchar(base[nb % ft_strlen(base)]);
	}
}

int	main(void)
{
	char a[] = "abc";
	int b = 123;
	ft_putnbr_base(b, a);
}
