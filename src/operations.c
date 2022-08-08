/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:58:45 by a          #+#    #+#             */
/*   Updated: 2022/06/27 17:46:36 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game *game, void *asset, int i, int j)
{
	mlx_put_image_to_window(game->mlx_obj, game->win_obj,
		asset, i, j);
}

void	updatemap(t_game *game, int y, int x)
{
	game->maps->map[game->character->char_pos[0] / 96 + y]
	[game->character->char_pos[1] / 96 + x] = '0';
	game->collectable_counter--;
}

void	collectable_updater(t_game *game, char key)
{
	int	i;

	i = -1;
	if (key == 'd')
		if (game->maps->map[game->character->char_pos[0] / 96]
			[(game->character->char_pos[1] / 96) + 1] == 'C')
			updatemap(game, 0, 1);
	if (key == 'w')
		if (game->maps->map[(game->character->char_pos[0] / 96) - 1]
			[(game->character->char_pos[1] / 96)] == 'C')
			updatemap(game, -1, 0);
	if (key == 's')
		if (game->maps->map[(game->character->char_pos[0] / 96) + 1]
			[(game->character->char_pos[1] / 96)] == 'C')
			updatemap(game, 1, 0);
	if (key == 'a')
		if (game->maps->map[game->character->char_pos[0] / 96]
			[(game->character->char_pos[1] / 96) - 1] == 'C')
			updatemap(game, 0, -1);
	if (game->collectable_counter == 1)
		put_opened_gate(game);
}

int	is_gated(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (game->maps->map[++i])
	{
		while (game->maps->map[i][++j])
		{
			if (game->maps->map[i][j] == 'E')
				if (game->character->char_pos[0] == i * 96)
					if (game->character->char_pos[1] == j * 96)
						return (exit_game(game));
		}
		j = -1;
	}
	return (0);
}

void	put_opened_gate(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (game->maps->map[++i])
	{
		while (game->maps->map[i][++j])
			if (game->maps->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_obj, game->win_obj,
					game->assets->opened_gate, j * 96, i * 96);
		j = 0;
	}
}
