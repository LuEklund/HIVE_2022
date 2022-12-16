/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:56:18 by leklund           #+#    #+#             */
/*   Updated: 2022/12/09 17:56:19 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int	ft_strlen(const char *str);

t_cords *save_cords(int x, int y)
{
	t_cords		*cords;

	cords = malloc(sizeof(t_cords));
	if (!cords)
		return (NULL);
	cords->x = x;
	cords->y = y;
	return (cords);
}

int save_collectable(t_collect **collect_ptr, int x, int y)
{
	t_collect	*new_collectable;
	t_collect	*curr_collectable;

	new_collectable = malloc(sizeof(t_collect));
	if (!new_collectable)
		return (0);
	new_collectable->cord = save_cords(x, y);
	new_collectable->next = NULL;
	curr_collectable = *collect_ptr;
	if (curr_collectable == NULL)
		*collect_ptr = new_collectable;
	else
	{
		while (curr_collectable->next != NULL)
			curr_collectable = curr_collectable->next;
		curr_collectable->next = new_collectable;
	}
	return (1);
}

int	containables(char *row, t_game *game,int y_axi)
{
	int	index;

	index = 0;
	while (row[index])
	{
		if (row[index] == 'C')
		{
			save_collectable(&game->collect, index, y_axi);
			game->collectables_amount += 1;
		}
		else if (row[index] == 'E')
		{
			if (game->exit != NULL)
				return (0);
			game->exit = save_cords(index, y_axi);
		}
		else if (row[index] == 'P')
		{
			if (game->player != NULL)
				return (0);
			game->player = save_cords(index, y_axi);
		}
		else if (row[index] != '0' && row[index] != '1')
			return (0);
		index++;
	}
	return (1);
}

int	check_1(char *row)
{
	int	index;

	index = 0;
	while (row[index])
	{
		if (row[index] != '1')
			return (0);
		index++;
	}
	return (1);
}

int	check_line(int len, char *line, int fd)
{
	int	new_line_len;

	new_line_len = ft_strlen(line);
	if (len != new_line_len)
	{
		if (get_next_line(fd) == NULL && (new_line_len == len - 1))
			return (1);
		else
			return (0);
	}
	else if (line[0] != '1' || line[len - 2] != '1' || line[len - 1] != '\n')
		return (0);
	return (1);
}
