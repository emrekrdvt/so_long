/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:57:55 by a          #+#    #+#             */
/*   Updated: 2022/05/16 17:57:56 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_clear_window(game->mlx_obj, game->win_obj);
	mlx_destroy_window(game->mlx_obj, game->win_obj);
	exit (1);
}

int	put_error(t_game *game, char *error)
{
	mlx_clear_window(game->mlx_obj, game->win_obj);
	mlx_destroy_window(game->mlx_obj, game->win_obj);
	ft_printf("%s", error);
	return (0);
}

int	put_map_error(char *error)
{
	ft_printf("%s", error);
	exit(0);
}
