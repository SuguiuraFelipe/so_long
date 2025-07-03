/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 21:25:24 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/03 21:22:53 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv)
{
    char **map;

    check_args(argc, argv);
    map = read_map(argv[1]);
    validate_rectangle_and_walls(map);
    validate_elements(map);
    validate_paths(map);
    start_game(map);
    return (0);
}