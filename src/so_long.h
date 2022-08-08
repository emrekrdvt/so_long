/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aa <aa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:58:53 by aa          #+#    #+#             */
/*   Updated: 2022/05/16 17:58:55 by aa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <libft.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game
{
	void				*mlx_obj;
	void				*img_obj;
	void				*win_obj;
	int					collectable_counter;
	struct s_character	*character;
	struct s_assets		*assets;
	struct s_map		*maps;
}	t_game;

typedef struct s_assets
{
	void	*background;
	void	*collectable;
	void	*block;
	void	*opened_gate;
	void	*closed_gate;
	void	*hero;
}	t_assets;

typedef struct s_map
{
	char	**map;
	char	*map_elem;
	int		last_index;
	int		last_j;
}	t_map;

typedef struct s_character
{
	int		char_pos[2];
	int		step_count;
}	t_character;

void	move_x2(t_game *game, int direction);
void	move_x(t_game *game, int direction);
int		run(int keycode, t_game *game);
int		put_map_error(char *error);
int		main(int argc, char **argv);
int		is_game_over(t_game *game);
int		character_checker(char **map);
int		openn(char *path, int fd);
void	put_img(t_game *game, void *asset, int i, int j);
void	collectable_updater(t_game *game, char key);
int		is_gated(t_game *game);
void	put_opened_gate(t_game *game);
int		exit_game(t_game *game);
int		put_error(t_game *game, char *error);
void	define_assets(t_game *game, void	*mlx_ptr, int *a, int *b);
void	put_bg(t_game *game, int a, int b);
void	character_pos_define(t_game *game, int i, int j);
t_game	*define_game(void);
int		is_valid4(char **map, int i, int j);
int		is_valid3(char **map, t_game *game, int j);
int		is_valid2(char **map, int last_index);
int		is_valid(char **map, int last_index, int last_j, t_game *game);
int		format_map(t_game *game, char **argv);
int		is_ber(char *format);
void	fill_map(t_game	*game, int i, int j);
int		control(t_game *game, char key, int j, int k);
int		if_moveable(t_game *game, char key);
int		run(int keycode, t_game *game);
int		is_movable2(t_game *game);
#endif
