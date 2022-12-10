#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

<<<<<<< HEAD
=======
int	save_map();

>>>>>>> 969cf1c06c8d637dc0c027ddb5417057a35125bd
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

<<<<<<< HEAD
typedef struct	s_cords{
	int	x;
	int	y;
}				t_cords;

// typedef struct	s_collect{
// 	t_cords				*cord;
// 	int					collectable;
// 	struct s_collect	*next;
// }				t_collect;

typedef struct	s_game {
	char		**map;
	int			player_moves;
	int			collectables_amount;
	// t_collect	*collect;
	t_cords		*exit;
	t_cords		*player;
}				t_game;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_game	*game;
}				t_vars;

typedef struct	s_rows{
	char	*row;
	struct s_rows	*next;
}				t_rows;

int	check_line(int len, char *line);
int	check_1(char *row);
int	containables(char *row, t_game *map, int y_axi);
int	save_map(t_game	*map);
int show_map(int keycode, t_vars *vars);
int player_move(int keycode, t_vars *vars);
=======
typedef struct	s_map_2d {
	char	**map;
}				t_map_2d;

typedef struct	s_map {
	char	*row;
	struct s_map	*next;
}				t_map;
>>>>>>> 969cf1c06c8d637dc0c027ddb5417057a35125bd

#endif