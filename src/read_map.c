/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:31:05 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/24 17:22:39 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	erro(char *msg)
{
	write(2, "Error\n", 6);
	while (*msg)
		write(2, msg++, 1);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

static void	trim_nl(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
}

static int	count_lines(const char *path)
{
	int		fd;
	char	*line;
	int		lines;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		erro("Opening map");
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

char	**read_map(const char *path)
{
	int		fd;
	int		i;
	char	**map;
	char	*line;
	
	i = count_lines(path);
	if (i < 3)
		erro("Map too small");
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		exit(EXIT_FAILURE);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		erro("Opening map");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		trim_nl(line);
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (close(fd), map);
}
