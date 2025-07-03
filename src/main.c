/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:25:24 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/03 17:03:34 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void ft_putendl(char *s)
{
    while (*s)
        write(1, s++, 1);
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    char **map;

    check_args(argc, argv);
    map = read_map(argv[1]);
    validate_rectangle_and_walls(map);
    validate_elements(map);
    validate_paths(map);
    ft_putendl("Paths OK");
    free_map(map);
    return (0);
}