/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 13:34:53 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/02/13 12:06:28 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*readfile(int fd, char *line, char *buffer)
{
	int	bytesread;

	if (buffer[0] != '\0')
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	while (!(ft_strchr(buffer, '\n')))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (free(line), NULL);
		buffer[bytesread] = '\0';
		if (bytesread == 0 && line[0] == '\0')
			return (free(line), NULL);
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (bytesread < BUFFER_SIZE)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (buffer[fd][0] = '\0', NULL);
	line[0] = '\0';
	line = readfile(fd, line, buffer[fd]);
	if (!line)
		return (buffer[fd][0] = '\0', NULL);
	ft_cleanbuff(buffer[fd]);
	return (line);
}

int	main(void)
{
	int		fd1;
	char	*line;
	int		number;

	fd1 = open("text", O_RDONLY);
	if (fd1 == -1)
		{
			printf("open() failded");
			return (1);
		}
	number = 1;
	while ((line = get_next_line(fd1)))
	{
		printf("line %i = %s", number, line);
		if (line)
			free(line);
		number++;
	}
	close(fd1);
	return (0);
}