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

int show_map(int keycode, t_vars *vars)
{
	int	index;

	index = 0;
	printf("%i\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	while (vars->game->map[index] != NULL)
	{
		printf("%s\n", vars->game->map[index]);
		index++;
	}
	printf("\n");
	return (0);
}

void	move_helper(t_vars *vars, int y, int x)
{
	t_game	*game;

	game = vars->game;
	// if (left_right)
	// {
		if (game->map[y][x] == '1')
			return ;
		if (game->map[y][x] == 'C')
			game->collectables_amount--;
		game->map[y][x] = 'P';
		game->map[game->player->y][game->player->x] = '0';
		game->player->x = x;
		game->player->y = y;
		game->player_moves += 1;
	// }
	// else
	// {
	// 	if (game->map[game->player->y + moves][game->player->x] == '1')
	// 		return ;
	// 	if (game->map[game->player->y + moves][game->player->x] == 'C')
	// 		game->collectables_amount--;
	// 	game->map[game->player->y + moves][game->player->x] = 'P';
	// 	game->map[game->player->y][game->player->x] = '0';
	// 	game->player->y += moves;
	// 	game->player_moves += 1;
	// }
	printf("player_moves[%d]\n", game->player_moves);
	printf("collectables_amount[%d]\n", game->collectables_amount);
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
	show_map(keycode, vars);
	return (0);
}
