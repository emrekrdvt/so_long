/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aa <aa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:58:36 by aa          #+#    #+#             */
/*   Updated: 2022/05/16 17:58:39 by aa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	control(t_game *game, char key, int j, int k)
{
	int	i;

	k = game->collectable_counter;
	i = game->character->char_pos[0];
	j = game->character->char_pos[1];
	if (key == 'd')
		if (game->maps->map[i / 96][(j / 96) + 1] == '1' ||
				(k > 1 && game->maps->map[i / 96][(j / 96) + 1] == 'E'))
			return (0);
	if (key == 'w')
		if (game->maps->map[(i / 96) - 1][(j / 96)] == '1'
			|| (k > 1 && game->maps->map[(i / 96) - 1][(j / 96)] == 'E'))
			return (0);
	if (key == 's')
		if (game->maps->map[(i / 96) + 1][(j / 96)] == '1'
				|| (k > 1 && game->maps->map[(i / 96) + 1][(j / 96)] == 'E'))
			return (0);
	if (key == 'a')
		if (game->maps->map[i / 96][(j / 96) - 1] == '1'
			|| (k > 1 && game->maps->map[i / 96][(j / 96) - 1] == 'E'))
			return (0);
	return (1);
}

int	if_moveable(t_game *game, char key)
{
	int		j;
	int		k;
	char	*s;

	j = 0;
	k = 0;
	if (!control(game, key, j, k))
		return (0);
	collectable_updater(game, key);
	ft_printf("%d\n", ++game->character->step_count);
	s = ft_itoa(game->character->step_count);
	put_img(game, game->assets->background, 0, 0);
	put_img(game, game->assets->block, 0, 0);
	mlx_string_put(game->mlx_obj, game->win_obj, 10, 10, 0x0000FF11, s);
	free(s);
	return (1);
}
