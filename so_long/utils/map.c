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

int save_row(t_map **sPtr, char *line, int len)
{
	char	*malloc_line;
	t_map	*new_map;
	t_map	*curr_map;

	malloc_line = malloc(sizeof(char) * len + 1);
	if (!malloc_line)
		return (0);
	malloc_line = ft_strdup(line);
	new_map = malloc(sizeof(t_map));
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


char	**make_map_2d(t_map **map, int y,char **map_2d)
{
	t_map	*curr_map;
	int		index;

	index =0;
	map_2d = malloc((sizeof(char*) * y) + 1);
	if (!map_2d)
		return (0);
	curr_map = *map;
	if (curr_map == NULL)
		return (0);
	while (curr_map->next != NULL)
	{
		map_2d[index] = curr_map->row;
		printf("%s",curr_map->row);
		curr_map = curr_map->next;
		index++;
	}
	printf("%s",curr_map->row);
	map_2d[index] = NULL;
	printf("%c", map_2d[1][1]);
	return (map_2d);
}

int	save_map()
{
	int		fd;
	char	*line;
	int		len;
	int		rows;
	t_map	*map = NULL;
	char	**map_2d;


	rows = 0;
	map_2d = NULL;
	fd = open("maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line != NULL)
	{
		printf("%d - ", ft_strlen(line));
		printf("%s", line);
		if (len != ft_strlen(line))
			return (1);
		save_row(&map, line, len);
		line = get_next_line(fd);
		rows++;
	}
	printf("%d", rows);
	close(fd);
	map_2d = make_map_2d(&map,rows,map_2d);
	printf("%c", map_2d[1][1]);
	return(0);
}

