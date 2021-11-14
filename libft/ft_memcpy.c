/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:08:25 by ctommy            #+#    #+#             */
/*   Updated: 2021/10/13 17:08:25 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	char	*destchar;
	char	*sourcechar;

	if (!dest && !source)
		return (NULL);
	destchar = (char *)dest;
	sourcechar = (char *)source;
	while (n--)
		*destchar++ = *sourcechar++;
	return (dest);
}
