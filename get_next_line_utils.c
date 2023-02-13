/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 11:19:03 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/02/13 12:08:52 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *string)
{
	int	index;

	index = 0;
	while (string[index])
		index++;
	return (index);
}

int	ft_strchr(char *buffer, char c)
{
	if (!buffer)
		return (0);
	while (*buffer)
	{
		if (*buffer == c)
			return (1);
		buffer++;
	}
	return (0);
}

int	ft_strchr_index(char *buffer, char c)
{
	int	index;

	index = 0;
	while (buffer[index])
	{
		if (buffer[index] == c)
			return (index + 1);
		index++;
	}
	return (index);
}

char	*ft_strjoin(char *line, char *buffer)
{
	int			index_line;
	int			index_buff;
	const int	lenght = ft_strlen(line) + ft_strchr_index(buffer, '\n');
	char		*new_line;

	new_line = malloc(sizeof(char) * (lenght + 1));
	if (!new_line)
		return (free(line), NULL);
	index_line = -1;
	while (line[++index_line])
		new_line[index_line] = line[index_line];
	index_buff = 0;
	while (buffer[index_buff] && buffer[index_buff] != '\n')
	{
		new_line[index_line + index_buff] = buffer[index_buff];
		index_buff++;
	}
	if (buffer[index_buff] == '\n')
		new_line[index_line + index_buff++] = '\n';
	new_line[index_line + index_buff] = '\0';
	return (free(line), new_line);
}

void	ft_cleanbuff(char *buffer)
{
	int	index;
	int	index_reset;

	index = 0;
	index_reset = 0;
	while (buffer[index] != '\n' && buffer[index])
		index++;
	if (buffer[index] == '\0')
	{
		buffer[0] = '\0';
		return ;
	}
	index++;
	while (buffer[index])
	{
		buffer[index_reset] = buffer[index];
		index++;
		index_reset++;
	}
	buffer[index_reset] = '\0';
}
