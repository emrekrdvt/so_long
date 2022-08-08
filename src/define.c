/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:57:26 by a          #+#    #+#             */
/*   Updated: 2022/06/27 18:12:29 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	character_pos_define(t_game *game, int i, int j)
{
	game->character->char_pos[0] = i * 96;
	game->character->char_pos[1] = j * 96;
}

void	fill_map(t_game	*game, int i, int j)
{
	i = -1;
	j = -1;
	while (game->maps->map[++i])
	{
		while (game->maps->map[i][++j])
		{
			if (game->maps->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_obj, game->win_obj,
					game->assets->block, j * 96, i * 96);
			else if (game->maps->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_obj, game->win_obj,
					game->assets->collectable, j * 96, i * 96);
			else if (game->maps->map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx_obj, game->win_obj,
					game->assets->hero, j * 96, i * 96);
				character_pos_define(game, i, j);
			}
			else if (game->maps->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_obj, game->win_obj,
					game->assets->closed_gate, j * 96, i * 96);
		}
		j = -1;
	}
}

t_game	*define_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->collectable_counter = 1;
	game->character = malloc(sizeof(t_character));
	game->maps = malloc(sizeof(t_map));
	game->mlx_obj = mlx_init();
	game->img_obj = mlx_init();
	game->character->step_count = 0;
	return (game);
}

void	put_bg(t_game *game, int a, int b)
{
	while (a <= game->maps->last_index * 96)
	{
		while (b <= game->maps->last_j * 96)
		{
			mlx_put_image_to_window(game->mlx_obj,
				game->win_obj, game->assets->background, b, a);
			b += 96;
		}
		a += 96;
		b = 0;
	}
}

void	define_assets(t_game *game, void	*mlx_ptr, int *a, int *b)
{
	game->assets = malloc(sizeof(t_assets));
	game->assets->background = mlx_xpm_file_to_image(mlx_ptr,
			"assets/0.xpm", a, b);
	game->assets->block = mlx_xpm_file_to_image(mlx_ptr,
			"assets/tree.xpm", a, b);
	game->assets->collectable = mlx_xpm_file_to_image(mlx_ptr,
			"assets/c.xpm", a, b);
	game->assets->hero = mlx_xpm_file_to_image(mlx_ptr,
			"assets/hero.xpm", a, b);
	game->assets->opened_gate = mlx_xpm_file_to_image(mlx_ptr,
			"assets/opened_gate.xpm", a, b);
	game->assets->closed_gate = mlx_xpm_file_to_image(mlx_ptr,
			"assets/closed_gate.xpm", a, b);
}
