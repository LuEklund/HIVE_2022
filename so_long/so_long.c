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
#include "libft/libft.h"

int	file_name(int argc, char **argv)
{
	char	*word;
	int		len;
	int		fd;

	if (argc != 2)
		error_message("please specify ONE map file");
	word = argv[1];
	len = ft_strlen(word);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4))
		error_message("map is not a .ber file");
	fd = open(word, O_RDONLY);
	if (fd < 0)
		error_message("file not found");
	return (fd);
}

int	save_images(t_vars *mlx)
{
	int		img_w;
	int		img_h;
	int		i;
	char	*text[5];

	text[0] = "./texture/Grass.xpm";
	text[1] = "./texture/Wall.xpm";
	text[2] = "./texture/Collect.xpm";
	text[3] = "./texture/Player.xpm";
	text[4] = "./texture/Exit.xpm";
	i = 0;
	mlx->img->img[0] = mlx_new_image(mlx->mlx, 16, 16);
	mlx->img->img[1] = mlx_xpm_file_to_image(mlx->mlx, text[0], &img_w, &img_h);
	mlx->img->img[2] = mlx_xpm_file_to_image(mlx->mlx, text[1], &img_w, &img_h);
	mlx->img->img[3] = mlx_xpm_file_to_image(mlx->mlx, text[2], &img_w, &img_h);
	mlx->img->img[4] = mlx_xpm_file_to_image(mlx->mlx, text[3], &img_w, &img_h);
	mlx->img->img[5] = mlx_xpm_file_to_image(mlx->mlx, text[4], &img_w, &img_h);
	while (i++ < 6)
	{
		if (!mlx->img->img[i])
			return (0);
	}
	return (1);
}

void	game_start(t_game *game)
{
	t_vars	mlx;
	t_data	img;

	mlx.game = game;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		error_print("mlx_int broke\n");
	mlx.win = mlx_new_window(mlx.mlx, 336, 336, "so_long");
	mlx_key_hook(mlx.win, player_move, &mlx);
	mlx.img = &img;
	mlx_hook(mlx.win, 17, 0, rec_cross_close, &mlx);
	if (!save_images(&mlx))
		error_message("Invalid image/s");
	mlx_loop_hook(mlx.mlx, &render_scene, &mlx);
	mlx_loop(mlx.mlx);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	fd = file_name(argc, argv);
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->collect = NULL;
	game->exit = NULL;
	game->player = NULL;
	game->player_moves = 0;
	game->coln = 0;
	game->winnable_exit = 0;
	game->winnable_collectable = 0;
	game->max_map = malloc(sizeof(t_cords));
	if (!game->max_map)
		error_print("malloc fail\n");
	save_map(game, fd);
	winnable_map(game);
	game_start(game);
	return (0);
}
