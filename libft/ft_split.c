/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:47:48 by a          #+#    #+#             */
/*   Updated: 2022/05/16 18:47:50 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (res);
}

char	**split_func(char const *s, char c, int *i, int *j)
{
	char	**res;
	int		d;
	int		f;

	f = 0;
	d = 0;
	res = malloc((count_word(s, c)) * sizeof(char *));
	if (!res)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			d = 0;
			while (*s && *s != c && ++d)
				++s;
			res[f++] = ft_substr(s - d, 0, d);
		}
		else
			++s;
	}
	res[f] = 0;
	*j = d;
	*i = f;
	return (res);
}

char	**ft_split(char const *s, char c, int *last_index, int *last_j)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || c < 0)
		return (NULL);
	res = split_func(s, c, &i, &j);
	*last_index = i - 1;
	*last_j = j;
	res[i] = 0;
	return (res);
}
