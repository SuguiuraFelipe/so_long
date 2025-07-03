/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:49:25 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/01 21:55:10 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *line;
	int readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	readbytes = 1;
	while (!has_new_line(line))
	{
		if (*buffer == '\0')
			readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
		{
			free(line);
			return (NULL);
		}
		if (readbytes == 0)
			return (line);
		line = copy_to_line(line, buffer);
		move_and_finish(buffer);
	}
    return (line);
}
