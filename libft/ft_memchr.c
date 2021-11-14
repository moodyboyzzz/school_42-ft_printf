/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:08:29 by ctommy            #+#    #+#             */
/*   Updated: 2021/10/13 17:08:29 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	char	*str;
	char	cc;

	str = (char *)arr;
	cc = (char)c;
	while (n--)
	{
		if (*str == cc)
			return (str);
		str++;
	}
	return (NULL);
}
