/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:59:03 by a          #+#    #+#             */
/*   Updated: 2022/06/27 19:14:10 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	character_checker(char **map)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				c++;
		}
	}
	if (c == 1)
		return (1);
	return (0);
}

int	is_ber(char *format)
{
	int	i;

	i = ft_strlen(format);
	if (format[i - 1] != 'r' && format[i - 2] != 'e'
		&& format[i - 3] != 'b' && format[i - 4] != '.')
		return (0);
	return (1);
}

int	is_game_over(t_game *game)
{
	if (game->collectable_counter == 1 && is_gated(game))
		exit(1);
	return (0);
}

int	openn(char *path, int fd)
{
	fd = open(path, O_RDONLY);
	return (fd);
}
