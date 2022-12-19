/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:40:50 by leklund           #+#    #+#             */
/*   Updated: 2022/12/08 20:40:52 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int	save_row(t_rows **sPtr, char *line, int len)
{
	char	*malloc_line;
	t_rows	*new_map;
	t_rows	*curr_map;

	malloc_line = malloc(sizeof(char) * len);
	if (!malloc_line)
		return (0);
	malloc_line = ft_strdup(line);
	malloc_line[len - 1] = '\0';
	new_map = malloc(sizeof(t_rows));
	if (!new_map)
		return (0);
	new_map->row = malloc_line;
	new_map->next = NULL;
	curr_map = *sPtr;
	if (curr_map == NULL)
		*sPtr = new_map;
	else
	{
		while (curr_map->next != NULL)
			curr_map = curr_map->next;
		curr_map->next = new_map;
	}
	return (1);
}

char	**make_map_2d(t_rows **rows, int y,t_game *game)
{
	t_rows	*curr_map;
	int		index;

	index = 0;
	game->map = malloc((sizeof(char*) * y) + 1);
	if (!game->map)
		return (0);
	curr_map = *rows;
	if (curr_map == NULL)
		return (0);
	if (!check_1 (curr_map->row))
		return (0);
	while (curr_map->next != NULL)
	{
		if (!containables (curr_map->row, game, index))
			return (0);
		game->map[index] = curr_map->row;
		curr_map = curr_map->next;
		index++;
	}
	if (!check_1 (curr_map->row) || !game->exit || !game->player || !game->collectables_amount)
		return (0);
	game->map[index] = curr_map->row;
	game->map[index + 1] = NULL;
	return (game->map);
}

int	save_map(t_game	*game, int fd)
{
	char	*line;
	int		len;
	int		y_axi;
	t_rows	*row = NULL;

	y_axi = 0;
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line != NULL)
	{
		if (!check_line(len, line, fd))
			error_message("Invalid line");
		if (!save_row(&row, line, len))
			error_message("Malloc fail");
		line = get_next_line(fd);
		y_axi++;
	}
	close(fd);
	game->map = make_map_2d(&row,y_axi,game);
	if (!game->map)
		error_message("Invalid Map");
	game->max_map->x = len - 1;
	game->max_map->y = y_axi;
	return (1);
}

