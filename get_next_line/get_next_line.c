/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:10:45 by leklund           #+#    #+#             */
/*   Updated: 2022/11/21 17:04:21 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	is_new_line(char *str, t_list *mem)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (count);
	while (str[count + mem->last] != '\0')
	{
		if (str[count + mem->last] == '\n')
		{
			count++;
			return (count);
		}
		count++;
	}
	return (0);
}

char	*return_str(char *tmp, t_list *mem)
{
	char	*str;
	int		length;

	length = is_new_line(mem->save, mem);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
	{
		free_all(mem, tmp);
		return (NULL);
	}
	ft_strlcpy(str, mem->save, length + 1);
	mem->last = mem->last + length;
	return (str);
}

void	save_str(char *tmp, t_list *mem)
{
	char	*tmp_old;

	if (mem->save)
	{
		tmp_old = ft_strdup(mem->save);
		free(mem->save);
		mem->save = ft_strjoin(tmp_old, tmp);
		free(tmp_old);
	}
	else
		mem->save = ft_strdup (tmp);
}

char	*reading(int fd, t_list *mem)
{
	char	*tmp;
	int		have_read;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
	{
		free_all(mem, tmp);
		return (NULL);
	}
	while (1)
	{
		if (is_new_line(mem->save, mem))
			break ;
		have_read = read (fd, tmp, BUFFER_SIZE);
		if (have_read == -1 || (have_read == 0 && mem->save == NULL))
		{
			free_all(mem, tmp);
			return (NULL);
		}
		if (!have_read)
		{
			free_all(mem, tmp);
			return (NULL);
		}
		tmp[have_read] = '\0';
		save_str(tmp, mem);
	}
	return (return_str(tmp, mem));
}

char	*get_next_line(int fd)
{
	static t_list	mem = { 0, NULL };

	if (!fd)
		return (NULL);
	return (reading(fd, &mem));
}
