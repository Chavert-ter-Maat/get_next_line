/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 11:21:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/01/03 13:23:41 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// DEFINE
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// INCLUDES
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

// FUNCTIONS
int		ft_strlen(char *str);
char	*ft_strjoin(char *file, char *buffer);
char	*readfile(int fd, char *line, char *buff);
char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);
int		ft_strchr_index(char *buff, char c);
void	ft_cleanbuff(char *buff);

#endif
