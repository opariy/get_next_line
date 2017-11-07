/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:33:29 by opariy            #+#    #+#             */
/*   Updated: 2017/06/23 14:34:12 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	static char*	tail;
	char buf[BUFF_SIZE + 1];
	int		n;
	int		i;

	i = 0;

	buf[BUFF_SIZE] = '\0';
	if (!tail)
		tail = ft_strnew(0);
	if (ft_strchr(tail, '\n'))
	{
		*line = ft_strsub(tail, 0, ft_strchr(tail, '\n') - tail);
		tail = ft_strchr(tail, '\n') + 1;
		return 1;
	}

	while ((n = read(fd, buf, BUFF_SIZE)) >= 0)
	{
		if (n < BUFF_SIZE)
			while (i < BUFF_SIZE - n)
			{
				buf[n + i] = '\0';
				i++;
			}
			i = 0;
		tail = ft_strjoin(tail, buf);

		if (ft_strchr(tail, '\n'))
		{
			//printf("1: %s\t", tail);
			*line = ft_strsub(tail, 0, ft_strchr(tail, '\n') - tail);
			tail = ft_strchr(tail, '\n') + 1;
			//printf("1_: %s\t", tail);
			return 1;
		}
		if (!n && !tail[0])
		{
			//printf("2: %s\t", tail);
			*line = ft_strnew(0);
			return (0);
		}
		if (n == 0)
		{
			//printf("3: %s\t", tail);
			*line = ft_strdup(tail);
			tail[0] = 0;
			return (1);
		}

	}
	return (-1);

}