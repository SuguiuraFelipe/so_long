/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:45:00 by fsuguiur             #+#    #+#             */
/*   Updated: 2025/07/03 18:33:36 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_player(t_game *g, int nx, int ny)
{
    if (g->map[ny][nx] == '1')
        return;
    if (g->map[ny][nx] == 'C')
        g->collectibles--;
    if (g->map[ny][nx] == 'E')
    {
        if (g->collectibles == 0)
            cleanup_game(g);
        else
            return;
    }
    g->map[g->player_y][g->player_x] = '0';
    g->map[ny][nx] = 'P';
    g->player_x = nx;
    g->player_y = ny;
    g->steps++;
    printf("Movements: %d\n", g->steps);
    render_map(g);
}

int handle_input(int keycode, t_game *g)
{
    int nx = g->player_x;
    int ny = g->player_y;

    if (keycode == 53 || keycode == 65307)
        cleanup_game(g);
    else if (keycode == 13 || keycode == 65362 || keycode == 119)
        ny--;
    else if (keycode == 1  || keycode == 65364 || keycode == 115)
        ny++;
    else if (keycode == 0  || keycode == 65361 || keycode == 97)
        nx--;
    else if (keycode == 2  || keycode == 65363 || keycode == 100)
        nx++;
    else
        return (0);
    move_player(g, nx, ny);
    return (0);
}

