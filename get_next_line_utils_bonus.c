/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 11:19:03 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/02/13 12:01:49 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	ft_strchr(char *buff, char c)
{
	if (!buff)
		return (0);
	while (*buff)
	{
		if (*buff == c)
			return (1);
		buff++;
	}
	return (0);
}

int	ft_strchr_index(char *buff, char c)
{
	int	index;

	index = 0;
	while (buff[index])
	{
		if (buff[index] == c)
			return (index + 1);
		index++;
	}
	return (index);
}

char	*ft_strjoin(char *line, char *buff)
{
	int			index;
	int			j;
	const int	len = ft_strlen(line) + ft_strchr_index(buff, '\n');
	char		*new_line;

	new_line = malloc(sizeof(char) * (len + 1));
	if (!new_line)
		return (free(line), NULL);
	index = -1;
	while (line[++index])
		new_line[index] = line[index];
	j = 0;
	while (buff[j] && buff[j] != '\n')
	{
		new_line[index + j] = buff[j];
		j++;
	}
	if (buff[j] == '\n')
		new_line[index + j++] = '\n';
	new_line[index + j] = '\0';
	return (free(line), new_line);
}

void	ft_cleanbuff(char *buff)
{
	int	index;
	int	index_reset;

	index = 0;
	index_reset = 0;
	while (buff[index] != '\n' && buff[index])
		index++;
	if (buff[index] == '\0')
	{
		buff[0] = '\0';
		return ;
	}
	index++;
	while (buff[index])
	{
		buff[index_reset] = buff[index];
		index++;
		index_reset++;
	}
	buff[index_reset] = '\0';
}
