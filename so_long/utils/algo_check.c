/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:51:16 by leklund           #+#    #+#             */
/*   Updated: 2022/12/12 11:51:18 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	search_paths(int y, int x, t_game *game)
{
	char	**map;
	if (game->winnable_exit && (game->collectables_amount == game->winnable_collectable))
		return ;
	map = game->map;
	if (map[y][x] == '1' || map[y][x] == '2')
		return ;
	else if (map[y][x] == 'C')
		game->winnable_collectable += 1;
	else if (map[y][x] == 'E')
		game->winnable_exit = 1;
	map[y][x] = '2';
	search_paths(y - 1, x, game);//UP
	search_paths(y + 1, x, game);//DOWN
	search_paths(y, x + 1, game);//RIGHT
	search_paths(y, x - 1, game);//LEFT
}

void	back_to_future(t_game *game)
{
	int			y;
	int			x;
	char		**map;
	t_collect	*collect;

	map = game->map;
	collect = game->collect;
	map[game->player->y][game->player->x] = 'P';
	map[game->exit->y][game->exit->x] = 'E';
	while (collect->next)
	{
		map[collect->cord->y][collect->cord->x] = 'C';
		collect = collect->next;
	}
	map[collect->cord->y][collect->cord->x] = 'C';
	y = 1;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == '2')
				map[y][x] = '0';
			x++;
		}
		y++;
	}
}

int	winnable_map(t_game *game)
{
	search_paths(game->player->y, game->player->x, game);
	if (!game->winnable_exit || (game->collectables_amount > game->winnable_collectable))
		error_message("Not beatable map");
	back_to_future(game);
	return (1);
}
