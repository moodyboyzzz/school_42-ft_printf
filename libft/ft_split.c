/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:30:33 by ctommy            #+#    #+#             */
/*   Updated: 2021/10/14 13:30:37 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_memandcpy(char *str, int ch, char const *s)
{
	char	*buf;

	str = (char *)malloc(sizeof(char) * (ch + 1));
	if (!str)
		return (NULL);
	buf = str;
	while (ch-- > 0)
		*buf++ = *s++;
	*buf = '\0';
	return (str);
}

static char	*ft_char(int i, char **res, char const *s, char c)
{
	int	sw;
	int	word;

	word = 0;
	while (*s)
	{
		sw = 0;
		if (*s != c)
		{
			while (*s != c && *s)
			{
				sw++;
				s++;
			}
			word++;
		}
		if (i == word - 1)
			return (ft_memandcpy(res[i], sw, s - sw));
		else
			s++;
	}
	return (0);
}

static int	ft_numstr(char const *s, char c)
{
	int	numstr;

	numstr = 0;
	while (*s)
	{
		if (*s != c)
		{
			numstr++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (numstr);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	words = ft_numstr(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < words)
	{
		res[i] = ft_char(i, res, s, c);
		if (res[i] == NULL)
			return (NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}
