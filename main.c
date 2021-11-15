/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:24 by ctommy            #+#    #+#             */
/*   Updated: 2021/11/14 14:16:25 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	p;

	p = printf(" %#x ;", 1);
	printf("%d\n", p);
	p = ft_printf(" %#x ;", 1);
	printf("%d\n", p);
	return (0);
}
