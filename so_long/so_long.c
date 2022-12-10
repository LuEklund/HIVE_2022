/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:55:12 by leklund           #+#    #+#             */
/*   Updated: 2022/12/06 15:55:17 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/so_long.h"


// char	*get_next_line(int fd);


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

<<<<<<< HEAD
void	game_start(t_game *game)
{
	t_vars	mlx;
	t_data	img;

	// printf("%s\n", map->map[0]);
	mlx.game = game;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 200, 180, "Hello world!");
	img.img = mlx_new_image(mlx.mlx, 200, 180);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_key_hook(mlx.win, player_move, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
}

int	main(void)
{
	t_game	*game = NULL;

	game = malloc(sizeof(t_game));
	if (!game)
		return(0);
	// game->collect = NULL;
	game->exit = NULL;
	game->player = NULL;
	game->player_moves = 0;
	game->collectables_amount = 0;
	// printf("\nC:\n");
	if (!save_map(game))
		return (0);
	// printf("%s\n", *map->map);
	game_start(game);
=======


int	main(void)
{
	save_map();
>>>>>>> 969cf1c06c8d637dc0c027ddb5417057a35125bd
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;



	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
	
	return (0);
}

