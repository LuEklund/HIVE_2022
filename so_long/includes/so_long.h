/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:30:26 by leklund           #+#    #+#             */
/*   Updated: 2022/12/20 18:30:30 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

typedef struct s_data{
	void	*img[6];
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_cords{
	int	x;
	int	y;
}				t_cords;

typedef struct s_collect{
	t_cords				*cord;
	struct s_collect	*next;
}				t_collect;

typedef struct s_game{
	char		**map;
	t_cords		*max_map;
	int			player_moves;
	int			coln;
	t_collect	*collect;
	t_cords		*exit;
	t_cords		*player;
	int			winnable_exit;
	int			winnable_collectable;
}				t_game;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	t_data	*img;
	t_game	*game;
}				t_vars;

typedef struct s_rows{
	char			*row;
	struct s_rows	*next;
}				t_rows;

int		check_line(int len, char *line, int fd);
int		check_1(char *row);
int		containables(char *row, t_game *map, int y_axi, int index);
int		save_map(t_game	*map, int fd);
int		show_map(int keycode, t_vars *vars);
int		player_move(int keycode, t_vars *vars);
int		winnable_map(t_game *game);
int		render_scene(t_vars *mlx);
void	error_message(char *str);
int		rec_cross_close(void);
void	error_print(char *str);

#endif
