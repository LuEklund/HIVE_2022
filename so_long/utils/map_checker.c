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

int	ft_strlen(const char *str);


t_cords *save_cords(int x, int y)
{
	t_cords		*cords;

	cords = malloc(sizeof(t_cords));
	if (!cords)
		return (NULL);
	// printf("\nA\n");
	cords->x = x;
	cords->y = y;
	// printf("\nA\n");
	return (cords);
}

// int save_collectable(t_collect **sPtr, int x, int y)
// {
// 	t_collect	*new_collectable;
// 	// t_cords		*cords;
// 	t_collect	*curr_collectable;

// 	new_collectable = malloc(sizeof(t_collect));
// 	if (!new_collectable)
// 		return (0);
// 	// printf("\n%d:%d\n",x,y);
// 	new_collectable->cord = save_cords(x, y);
// 	new_collectable->next = NULL;

// 	curr_collectable = *sPtr;
// 	if (curr_collectable == NULL)
// 		*sPtr = new_collectable;
// 	else
// 	{
// 		while (new_collectable->next != NULL)
// 			new_collectable = new_collectable->next;
// 		new_collectable->next = new_collectable;
// 	}
// 	return (1);
// }
// if (row[index] == 'C')
// 		{
// 			save_collectable(&game->collect, index, y_axi);
// 			game->collectables_amount += 1;
// 		}

int	containables(char *row, t_game *game,int y_axi)
{
	int	index;

	index = 0;
	while (row[index])
	{
		if (row[index] == 'C')
			game->collectables_amount += 1;
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

int	check_line(int len, char *line)
{
	// printf("%d - ", ft_strlen(line));
	// printf("%s", line);
	if (len != ft_strlen(line))
		return (0);
	else if (line[0] != '1' || line[len - 2] != '1')
		return (0);
	return (1);
}
