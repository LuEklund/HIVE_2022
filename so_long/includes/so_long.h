#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

int	save_map();

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_map_2d {
	char	**map;
}				t_map_2d;

typedef struct	s_map {
	char	*row;
	struct s_map	*next;
}				t_map;

#endif