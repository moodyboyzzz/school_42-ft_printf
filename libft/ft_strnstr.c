/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:08:04 by ctommy            #+#    #+#             */
/*   Updated: 2021/10/13 17:08:04 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*copy;

	i = 0;
	copy = (char *)str1;
	n_len = ft_strlen(str2);
	if (n_len == 0 || str1 == str2 || str2 == NULL)
		return (copy);
	while (copy[i] && i < len)
	{
		j = 0;
		while (copy[i + j] && str2[j] && copy[i + j]
			== str2[j] && ((i + j) < len))
			j++;
		if (j == n_len)
			return (copy + i);
		i++;
	}
	return (0);
}
