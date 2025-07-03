/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:34:58 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/03 16:51:42 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **dup_map(char **map)
{
    char    **copy;
    int     rows;
    int     i;
    int     len;

    rows = 0;
    while (map[rows])
        rows++;
    copy = malloc((rows + 1) * sizeof(char *));
    if (!copy)
        exit(EXIT_FAILURE);
    i = 0;
    while (map[i])
    {
        len = (int)strlen(map[i]);
        copy[i] = malloc(len + 1);
        if (!copy[i])
            exit(EXIT_FAILURE);
        memcpy(copy[i], map[i], len + 1);
        i++;
    }
    copy[i] = NULL;
    return (copy);
}
