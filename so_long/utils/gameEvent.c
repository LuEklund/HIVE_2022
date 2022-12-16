/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameEvent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:31:32 by leklund           #+#    #+#             */
/*   Updated: 2022/12/09 19:31:33 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
//HERE IS THE MAP SHHOWER WHEN MOVE!!!!
void	ft_putchar(char c)
{
	write(1,&c,1);
}

void	put_moves(long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		put_moves(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
	{
		ft_putchar(n + '0');
	}
}

void	move_helper(t_vars *vars, int y, int x)
{
	t_game	*game;

	game = vars->game;
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
		game->collectables_amount--;
	else if (game->map[y][x] == 'E' && !game->collectables_amount)
	{
		put_moves(game->player_moves + 1);
		ft_putchar('\n');
		exit (0);
	}
	if ((game->player->x == game->exit->x) && (game->player->y == game->exit->y))
		game->map[game->player->y][game->player->x] = 'E';
	else
		game->map[game->player->y][game->player->x] = '0';
	game->map[y][x] = 'P';
	game->player->x = x;
	game->player->y = y;
	game->player_moves += 1;
	put_moves(game->player_moves);
	ft_putchar('\n');
}

int player_move(int keycode, t_vars *vars)
{
	int	player_x;
	int	player_y;

	player_x = vars->game->player->x;
	player_y = vars->game->player->y;
	if (keycode == 13)//UPP
		move_helper(vars, player_y - 1, player_x);
	else if (keycode == 1)//DOWN
		move_helper(vars, player_y + 1, player_x);
	else if (keycode == 0)//LEFT
		move_helper(vars, player_y, player_x - 1);
	else if (keycode == 2)//RIGHT
		move_helper(vars, player_y, player_x + 1);
	else if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	// render_scene(vars);
	return (0);
}
