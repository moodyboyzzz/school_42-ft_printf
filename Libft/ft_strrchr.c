/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:08:01 by ctommy            #+#    #+#             */
/*   Updated: 2021/10/13 17:08:01 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*strrc;
	char	chc;

	strrc = (char *) str + ft_strlen(str);
	chc = (char) ch;
	while (strrc >= str)
	{
		if (*strrc == chc)
			return (strrc);
		strrc--;
	}
	return (NULL);
}
