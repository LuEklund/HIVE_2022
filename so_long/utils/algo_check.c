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

	if (game->winnable_exit && (game->coln == game->winnable_collectable))
		return ;
	map = game->map;
	if (map[y][x] == '1' || map[y][x] == '2')
		return ;
	else if (map[y][x] == 'C')
		game->winnable_collectable += 1;
	else if (map[y][x] == 'E')
		game->winnable_exit = 1;
	map[y][x] = '2';
	search_paths(y - 1, x, game);
	search_paths(y + 1, x, game);
	search_paths(y, x + 1, game);
	search_paths(y, x - 1, game);
}

void	collect_back(char **map, t_game *game)
{
	t_collect	*collect;

	collect = game->collect;
	map[game->player->y][game->player->x] = 'P';
	map[game->exit->y][game->exit->x] = 'E';
	while (collect->next)
	{
		map[collect->cord->y][collect->cord->x] = 'C';
		collect = collect->next;
	}
	map[collect->cord->y][collect->cord->x] = 'C';
}

void	back_to_future(t_game *game)
{
	int			y;
	int			x;
	char		**map;

	map = game->map;
	collect_back(map, game);
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
	if (!game->winnable_exit || (game->coln > game->winnable_collectable))
		error_print("Not beatable map\n");
	back_to_future(game);
	return (1);
}
