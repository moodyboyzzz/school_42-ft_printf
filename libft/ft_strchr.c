/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:08:17 by ctommy            #+#    #+#             */
/*   Updated: 2021/10/13 17:08:17 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*strc;
	char	chc;

	strc = (char *) str;
	chc = (char) ch;
	while (*strc && *strc != chc)
		strc++;
	if (*strc == chc)
		return (strc);
	return (NULL);
}
