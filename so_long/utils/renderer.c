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

int	render_scene(t_vars *mlx)
{
	int	x;
	int y;
	t_cords	*player;
	char	type;
	t_cords	where;

	if(!mlx->win)
		printf("[AAAA]\n");
	player = mlx->game->player;
	y = -10;
	where.x = 0;
	where.y = 0;
	while (y <= 10)
	{
		where.x = 0;
		x = -10;
		while (x <= 10)
		{
			if (player->x + x < 0 || player->x + x > mlx->game->max_map->x - 1)
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img[0], (where.x) * 16, (where.y) * 16);
			}
			else if (player->y + y < 0 || player->y + y > mlx->game->max_map->y - 1)
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img[0], (where.x) * 16, (where.y) * 16);
			}
			else
			{
				// printf("y[%i], x[%i]\n", player->y + y,player->x + x);
				type = mlx->game->map[player->y + y][player->x + x];
				if (type == '0')
					mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img[1], (where.x) * 16, (where.y) * 16);
				else if (type == '1')
					mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img[2], (where.x) * 16, (where.y) * 16);
				else if (type == 'C')
					mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img[3], (where.x) * 16, (where.y) * 16);
				else if (type == 'P')
					mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img[4], (where.x) * 16, (where.y) * 16);
				else if (type == 'E')
					mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img[5], (where.x) * 16, (where.y) * 16);
				// else
				// 	put_stuff(mlx, 0);
			}
			// printf("Wy[%i], Wx[%i]\n", where.y, where.x); 
			
			where.x += 1;
			x++;
		}
		where.y += 1;
		y++;
	}
	return(0);
}