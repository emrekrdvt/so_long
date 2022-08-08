/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:58:27 by a          #+#    #+#             */
/*   Updated: 2022/06/27 19:14:50 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid4(char **map, int i, int j)
{
	char	param[4];

	param[3] = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				param[0] = 't';
			if (map[i][j] == 'C')
				param[1] = 't';
			if (map[i][j] == 'P')
				param[2] = 't';
		}
		j = -1;
	}
	i = -1;
	while (++i < 3)
		if (param[i] != 't')
			return (put_map_error("Error\nMapte eksik karakter"));
	if (!character_checker(map))
		return (put_map_error("Error\nBirden fazla karakter"));
	return (1);
}

int	is_valid3(char **map, t_game *game, int i)
{
	int	j;
	int	a;
	int	b;

	b = -1;
	a = -1;
	j = -1;
	while (map[i][++j])
	{
		if (map[i][j] != 'P' && map[i][j] != '0'
			&& map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '1')
			return (put_map_error("Error\nMapte tanimsiz karakter"));
		else if (map[i][j] == 'C')
			game->collectable_counter++;
	}
	if (!is_valid4(map, a, b))
		return (0);
	return (j);
}

int	is_valid2(char **map, int last_index)
{
	int	i;

	i = -1;
	while (map[0][++i])
		if (map[0][i] != '1')
			return (put_map_error("Error\nMapte duvar eksik"));
	i = -1;
	while (map[last_index][++i])
		if (map[last_index][i] != '1')
			return (put_map_error("Error\nMapte duvar eksik"));
	return (1);
}

int	is_valid(char **map, int last_index, int last_j, t_game *game)
{
	int		i;
	char	param[4];
	int		j;

	i = -1;
	param[3] = 0;
	while (param[++i])
		param[i] = 'f';
	i = -1;
	if (!is_valid2(map, last_index))
		put_map_error("Error\nMapte duvar eksik");
	while (map[++i])
	{
		j = is_valid3(map, game, i);
		if (j != last_j || map[i][j - 1] != '1')
			return (put_map_error("Error\nMap hatali"));
	}
	return (1);
}

int	format_map(t_game *game, char **argv)
{
	char	x[2];
	int		fd;

	game->maps->map_elem = malloc(sizeof(char));
	if (!game->maps->map_elem)
		return (put_map_error("Error\nMalloc hatasi"));
	game->maps->map_elem[0] = 0;
	x[1] = 0;
	if (!is_ber(argv[1]))
		return (put_map_error("Error\nMap dosyasi formati yanlis"));
	fd = 1;
	fd = openn(argv[1], fd);
	if (fd < 0)
		return (put_map_error("Error\nMap dosyasi acilamadi"));
	while (read(fd, x, 1))
		game->maps->map_elem = ft_strjoin(game->maps->map_elem, x);
	if (game->maps->map_elem[0] == 0)
		return (put_map_error("Error\nMap dosyasi bos"));
	game->maps->map = ft_split(game->maps->map_elem, '\n',
			&(game->maps->last_index), &(game->maps->last_j));
	if (!(is_valid(game->maps->map, game->maps->last_index,
				game->maps->last_j, game)))
		return (0);
	ft_printf("%s", game->maps->map_elem);
	return (1);
}
