/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:56:54 by leklund           #+#    #+#             */
/*   Updated: 2022/12/14 16:56:56 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

int	put_img(t_vars *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x * 16, y * 16);
	return (1);
}

void	what_put(int x, int y, t_cords where, t_vars *mlx)
{
	t_cords	*player;
	char	type;

	player = mlx->game->player;
	if (player->x + x < 0 || player->x + x > mlx->game->max_map->x - 1)
		put_img(mlx, mlx->img->img[0], where.x, where.y);
	else if (player->y + y < 0 || player->y + y > mlx->game->max_map->y - 1)
		put_img(mlx, mlx->img->img[0], where.x, where.y);
	else
	{
		type = mlx->game->map[player->y + y][player->x + x];
		if (type == '0')
			put_img(mlx, mlx->img->img[1], where.x, where.y);
		else if (type == '1')
			put_img(mlx, mlx->img->img[2], where.x, where.y);
		else if (type == 'C')
			put_img(mlx, mlx->img->img[3], where.x, where.y);
		else if (type == 'P')
			put_img(mlx, mlx->img->img[4], where.x, where.y);
		else if (type == 'E')
			put_img(mlx, mlx->img->img[5], where.x, where.y);
	}	
}

int	render_scene(t_vars *mlx)
{
	int		x;
	int		y;
	t_cords	where;

	y = -10;
	where.x = 0;
	where.y = 0;
	while (y <= 10)
	{
		where.x = 0;
		x = -10;
		while (x <= 10)
		{
			what_put(x, y, where, mlx);
			where.x += 1;
			x++;
		}
		where.y += 1;
		y++;
	}
	return (0);
}
