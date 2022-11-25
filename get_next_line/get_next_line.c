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

char	*return_str(t_list *mem)
{
	char	*str;
	int		length;

	length = is_new_line(mem->save, mem);
	if (!length)
		length = ft_strlen(mem->save + mem->last);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, mem->save + mem->last, length + 1);
	mem->last = mem->last + length;
	return (str);
}

void	save_str(char *tmp, t_list *mem)
{
	if (mem->save)
		mem->save = ft_strjoin(mem->save, tmp);
	else
		mem->save = ft_strdup (tmp);
}

char	*reading(int fd, t_list *mem, char *tmp)
{
	int		readen;

	while (1)
	{
		if (is_new_line(mem->save, mem))
			break ;
		readen = read (fd, tmp, BUFFER_SIZE);
		if (readen == -1 || !readen)
		{
			if (mem->save && ft_strlen(mem->save + mem->last))
				break ;
			else
			{
				if (mem->save)
				{
					free(mem->save);
					mem->save = NULL;
				}
				return (NULL);
			}
		}
		tmp[readen] = '\0';
		save_str(tmp, mem);
	}
	return (return_str(mem));
}

char	*get_next_line(int fd)
{
	static t_list	mem = {0, NULL};
	char			*tmp;
	char			*return_str;

	if (fd < 0)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	return_str = reading(fd, &mem, tmp);
	if (tmp != NULL)
	{
		free(tmp);
	}
	return (return_str);
}
