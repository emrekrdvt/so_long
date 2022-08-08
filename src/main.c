/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaradav <ekaradav@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:58:16 by ekaradav          #+#    #+#             */
/*   Updated: 2022/06/05 17:30:13 by ekaradav         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_x2(t_game *game, int direction)
{
	if (direction == 2 && if_moveable(game, 's'))
	{
		put_img(game, game->assets->background,
			game->character->char_pos[1], game->character->char_pos[0] + 96);
		put_img(game, game->assets->hero,
			game->character->char_pos[1], game->character->char_pos[0] + 96);
		put_img(game, game->assets->background,
			game->character->char_pos[1], game->character->char_pos[0]);
		game->character->char_pos[0] += 96;
		if (is_game_over(game))
			return ;
	}
	else if (direction == 3 && if_moveable(game, 'a'))
	{
		put_img(game, game->assets->background,
			game->character->char_pos[1] - 96, game->character->char_pos[0]);
		put_img(game, game->assets->hero,
			game->character->char_pos[1] - 96, game->character->char_pos[0]);
		put_img(game, game->assets->background,
			game->character->char_pos[1], game->character->char_pos[0]);
		game->character->char_pos[1] -= 96;
		if (is_game_over(game))
			return ;
	}
}

void	move_x(t_game *game, int direction)
{
	if (direction == 0 && if_moveable(game, 'd'))
	{
		put_img(game, game->assets->background,
			game->character->char_pos[1] + 96, game->character->char_pos[0]);
		put_img(game, game->assets->hero,
			game->character->char_pos[1] + 96, game->character->char_pos[0]);
		put_img(game, game->assets->background,
			game->character->char_pos[1], game->character->char_pos[0]);
		game->character->char_pos[1] += 96;
		if (is_game_over(game))
			return ;
	}
	else if (direction == 1 && if_moveable(game, 'w'))
	{
		put_img(game, game->assets->background,
			game->character->char_pos[1], game->character->char_pos[0] - 96);
		put_img(game, game->assets->hero,
			game->character->char_pos[1], game->character->char_pos[0] - 96);
		put_img(game, game->assets->background,
			game->character->char_pos[1], game->character->char_pos[0]);
		game->character->char_pos[0] -= 96;
		if (is_game_over(game))
			return ;
	}
}

int	run(int keycode, t_game *game)
{
	if (keycode == 2)
		move_x(game, 0);
	else if (keycode == 13)
		move_x(game, 1);
	else if (keycode == 1)
		move_x2(game, 2);
	else if (keycode == 0)
		move_x2(game, 3);
	else if (keycode == 53)
	{
		mlx_clear_window(game->mlx_obj, game->win_obj);
		mlx_destroy_window(game->mlx_obj, game->win_obj);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		a;
	int		b;

	if (argc == 2)
	{
		game = define_game();
		if (!format_map(game, argv))
			return (0);
		game->win_obj = mlx_new_window(game->mlx_obj, game->maps->last_j * 96,
				(game->maps->last_index + 1) * 96, "OYUN KNK");
		define_assets(game, game->img_obj, &a, &b);
		put_bg(game, 0, 0);
		fill_map(game, a, b);
		mlx_hook(game->win_obj, 2, 1L << 0, run, game);
		mlx_hook(game->win_obj, 17, 0, exit_game, game);
		mlx_loop(game->mlx_obj);
	}
	else
	{
		ft_printf("Arguman eksik");
		return (0);
	}
}
