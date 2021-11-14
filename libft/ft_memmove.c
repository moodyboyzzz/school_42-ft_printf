/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:08:22 by ctommy            #+#    #+#             */
/*   Updated: 2021/10/13 17:08:22 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	char	*dchar;
	char	*schar;

	if (!dest && !source)
		return (NULL);
	dchar = (char *)dest;
	schar = (char *)source;
	if (dchar > schar)
	{
		dchar += n;
		schar += n;
		while (n--)
			*--dchar = *--schar;
	}
	else
		while (n--)
			*dchar++ = *schar++;
	return (dest);
}
