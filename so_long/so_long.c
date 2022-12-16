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

int	rec_cross_close()
{
	exit(0);
}
// mlx_mouse_hook(mlx.win, key_hook, &mlx);

int	save_images(t_vars *mlx)
{
	int		img_width;
	int		img_height;

	mlx->img->img[0] = mlx_new_image(mlx->mlx, 16, 16)
	mlx->img->img[1] = mlx_xpm_file_to_image(mlx->mlx, "./texture/Grass.xpm", &img_width, &img_height);
	mlx->img->img[2] = mlx_xpm_file_to_image(mlx->mlx, "./texture/Wall.xpm", &img_width, &img_height);
	mlx->img->img[3] = mlx_xpm_file_to_image(mlx->mlx, "./texture/Collect.xpm", &img_width, &img_height);
	mlx->img->img[4] = mlx_xpm_file_to_image(mlx->mlx, "./texture/Player.xpm", &img_width, &img_height);
	mlx->img->img[5] = mlx_xpm_file_to_image(mlx->mlx, "./texture/Exit.xpm", &img_width, &img_height);
	return (1);
}

void	game_start(t_game *game)
{
	t_vars	mlx;
	t_data	img;

	mlx.game = game;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 336, 336, "so_long");
	mlx_key_hook(mlx.win, player_move, &mlx);
	mlx.img = &img;
	mlx_hook(mlx.win, 17, 0, rec_cross_close, &mlx);
	save_images(&mlx);
	if (!save_images)
		exit(0);
	mlx_loop_hook(mlx.mlx, &render_scene, &mlx);
	mlx_loop(mlx.mlx);
}

int	main(void)
{
	t_game	*game = NULL;

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->collect = NULL;
	game->exit = NULL;
	game->player = NULL;
	game->player_moves = 0;
	game->collectables_amount = 0;
	game->winnable_exit = 0;
	game->winnable_collectable = 0;
	game->max_map = malloc(sizeof(t_cords));
	if (!game->max_map)
		return (0);
	if (!save_map(game))
		return (0);
	if (!winnable_map(game))
		return (0);
	game_start(game);
	return (0);
}
