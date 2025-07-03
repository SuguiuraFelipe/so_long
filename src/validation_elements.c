/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:16:57 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/02 18:16:30 by fsuguiur         ###   ########.fr       */
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

/* valida apenas caracteres permitidos */
static void  validate_chars(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != 'P' && map[i][j] != 'E' &&
                map[i][j] != 'C' && map[i][j] != '0' &&
                map[i][j] != '1')
                erro("Invalid character in map");
            j++;
        }
        i++;
    }
}

/* conta P, E e C e valida quantidades */
static void  validate_counts(char **map)
{
    int     p;
    int     e;
    int     c;
    char    *t;

    p = 0;
    c = 0;
    e = 0;
    while (*map)
    {
        t = *map++;
        while (*t)
        {
            if (*t == 'P')
                p++;
            else if (*t == 'E')
                e++;
            else if (*t == 'C')
                c++;
            t++;
        }
    }
    if (p != 1 || e != 1 || c < 1)
        erro("Map must have 1P, 1E and at least 1C");
}

/* função pública chamada por main */
void  validate_elements(char **map)
{
    validate_chars(map);
    validate_counts(map);
}
