/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:41:08 by pfrey             #+#    #+#             */
/*   Updated: 2017/03/11 16:04:35 by pfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		str_fill(char *buffer, char **str)
{
	char	*temp;

	temp = *str;
	if (*str == NULL)
	{
		if ((*str = ft_strdup(buffer)) == NULL)
			return (-1);
	}
	else
	{
		if ((*str = ft_strjoin(temp, buffer)) == NULL)
			return (-1);
		free(temp);
	}
	return (1);
}

int		line_fill(char **line, char **str)
{
	size_t		size;
	char		*temp_ptr;
	char		*new_str;

	size = ft_strclen(*str, CHAR);
	*line = ft_memalloc(size + 1);
	ft_memcpy(*line, *str, size);
	temp_ptr = ft_strchr(*str, CHAR);
	if ((new_str = ft_strdup(++temp_ptr)) == NULL)
		return (-1);
	free(*str);
	*str = new_str;
	return (1);
}

int		end_of_file(char **line, char **str, char *buffer)
{
	str_fill(buffer, str);
	if (ft_strlen(*str) > 0)
	{
		if (ft_strchr(*str, CHAR) != NULL)
			line_fill(line, &(*str));
		else
		{
			if ((*line = ft_strdup(*str)) == NULL)
				return (-1);
			free(*str);
			*str = NULL;
		}
	}
	else
		return (0);
	return (1);
}

void	free_old_str(char **str)
{
	if (*str != NULL)
		free(*str);
}

int		get_next_line(const int fd, char **line)
{
	int				file_read;
	char			buffer[BUFF_SIZE + 1];
	static t_gnl	gnl;

	if (gnl.old_fd != fd)
	{
		gnl.old_fd = fd;
		free_old_str(&gnl.str);
		gnl.str = NULL;
	}
	file_read = read(fd, buffer, BUFF_SIZE);
	buffer[file_read] = '\0';
	if (file_read == BUFF_SIZE)
	{
		str_fill(buffer, &gnl.str);
		if (ft_strchr(gnl.str, CHAR) == NULL)
			get_next_line(fd, line);
		else
			line_fill(line, &gnl.str);
	}
	else if (file_read < BUFF_SIZE && file_read >= 0)
		return (end_of_file(line, &gnl.str, buffer));
	else
		return (-1);
	return (1);
}
