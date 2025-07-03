/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:31:05 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/02 17:14:28 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void  erro(char *msg)
{
    write(2, "Error\n", 6);
    while (*msg)
        write(2, msg++, 1);
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
}

static void  trim_nl(char *s)
{
    int len = 0;
    while (s[len])
        len++;
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';
}

static int  count_lines(const char *path)
{
    int     fd;
    char    *line;
    int     lines;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        erro("Opening map");
    lines = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        lines++;
        free(line);
    }
    close(fd);
    return (lines);
}

char    **read_map(const char *path)
{
    int     fd;
    int     lines;
    char    **map;
    char    *line;
    int     i;

    lines = count_lines(path);
    if (lines < 3)
        erro("Map too small");
    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        exit(EXIT_FAILURE);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        erro("Opening map");
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        trim_nl(line);
        map[i++] = line;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}