/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 06:13:36 by mi                #+#    #+#             */
/*   Updated: 2023/02/01 06:14:41 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *get_next_line_3(char *str)
{
	int i;
	char *line;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		line = ft_substr(str, 0, i + 1);
		ft_strcpy(str, str + i + 1);
	}
	else
	{
		line = ft_strdup(str);
		*str = '\0';
	}
	return (line);
}

static char *exception(char *line, char *backup, int read_size)
{
	if (read_size <= 0)
	{
		if (*line != '\0')
			return (line);
		if (backup != NULL)
		{
			free(backup);
			backup = NULL;
		}
		free(line);
		line = NULL;
	}
	return (line);
}

static int get_next_line_2(int fd, char **backup)
{
	char *buf;
	char *temp;
	int read_size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || *backup == NULL)
		return (-1);
	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size < 0)
	{
		free(buf);
		return (read_size);
	}
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		temp = *backup;
		*backup = ft_strjoin(*backup, buf);
		free(temp);
		if (ft_strchr(*backup, '\n') || *backup == NULL)
			break;
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (read_size);
}

char *get_next_line(int fd)
{
	static char *backup;
	char *line;
	int read_size;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup)
		backup = ft_strdup("");
	read_size = get_next_line_2(fd, &backup);
	if (read_size == -1 || backup == NULL)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	line = get_next_line_3(backup);
	if (!line)
		return (NULL);
	if (read_size <= 0 && *line == '\0')
	{
		free(backup);
		backup = NULL;
	}
	return (exception(line, backup, read_size));
}
