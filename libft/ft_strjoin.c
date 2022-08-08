/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:48:03 by a          #+#    #+#             */
/*   Updated: 2022/05/16 18:48:05 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*newstr;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = 0;
	newstr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		newstr[j++] = s2[i];
		i++;
	}	
	newstr[j] = '\0';
	free(s1);
	return (newstr);
}
