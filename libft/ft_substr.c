/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:07:59 by ctommy            #+#    #+#             */
/*   Updated: 2021/10/13 17:07:59 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (len <= 0 || !s || start >= ft_strlen(s))
		return (ft_strdup(""));
	i = ft_strlen(&s[start]);
	if (i < len)
		len = i;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = start;
	while (s[i] && ((i - start) < len))
	{
		sub[i - start] = s[i];
		i++;
	}
	sub[i - start] = '\0';
	return (sub);
}
