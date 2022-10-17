/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:07:45 by del-yaag          #+#    #+#             */
/*   Updated: 2022/09/13 13:20:42 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_abs.h"
#include "ft_abs.h"
#include <stdio.h>

int main(void)
{
	char	index;

	index = 'a';
	while (index < 'z')
	{
		printf("macros::abs(%c) = %c\n", index, ABS(index));
		index++;
	}

}
