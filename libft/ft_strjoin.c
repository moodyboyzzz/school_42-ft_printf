/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:13:22 by ctommy            #+#    #+#             */
/*   Updated: 2021/10/14 13:13:23 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*constr;
	size_t	len1;
	size_t	len2;

	if (!s1)
		return (ft_strdup(""));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	constr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!constr)
		return (NULL);
	while (*s1)
		*constr++ = *s1++;
	*constr = 0;
	constr -= len1;
	ft_strlcat(constr, s2, len1 + len2 + 1);
	return (constr);
}
