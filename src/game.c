/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:12:10 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/03 21:28:14 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <string.h>

#define TILE 64

static int  handle_destroy(t_game *g)
{
    cleanup_game(g);
    return (0);
}

static void init_game_data(t_game *g)
{
    int y;
    int x;

    g->collectibles = 0;
    y = 0;
    while (g->map[y])
    {
        x = 0;
        while (g->map[y][x])
        {
            if (g->map[y][x] == 'P')
            {
                g->player_x = x;
                g->player_y = y;
            }
            else if (g->map[y][x] == 'C')
                g->collectibles++;
            x++;
        }
        y++;
    }
}

void start_game(char **map)
{
    t_game *g;

    g = malloc(sizeof(*g));
    if (!g)
        exit(EXIT_FAILURE);
    g->map = map;
    g->rows = 0;
    while (map[g->rows])
        g->rows++;
    g->cols = (int)strlen(map[0]);
    g->steps = 0;
    init_game_data(g);
    g->mlx_ptr = mlx_init();
    g->win_ptr = mlx_new_window(g->mlx_ptr,
        g->cols * TILE, g->rows * TILE, "so_long");
    load_images(g);
    render_map(g);
    mlx_do_key_autorepeatoff(g->mlx_ptr);
    mlx_hook(g->win_ptr, 2, 1L<<0, handle_input, g);
    mlx_hook(g->win_ptr, 3, 1L<<1, handle_input, g);
    mlx_hook(g->win_ptr, 17, 0L, handle_destroy, g);
    mlx_loop(g->mlx_ptr);
}
