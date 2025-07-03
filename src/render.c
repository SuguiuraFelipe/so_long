/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:10:27 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/03 18:14:11 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#define TILE 64

void load_images(t_game *g)
{
    int w, h;

    g->img_floor       = mlx_xpm_file_to_image(g->mlx_ptr,
                          "assets/floor.xpm", &w, &h);
    g->img_wall        = mlx_xpm_file_to_image(g->mlx_ptr,
                          "assets/building.xpm", &w, &h);
    g->img_collectible = mlx_xpm_file_to_image(g->mlx_ptr,
                          "assets/pill.xpm", &w, &h);
    g->img_exit        = mlx_xpm_file_to_image(g->mlx_ptr,
                          "assets/morpheus.xpm", &w, &h);
    g->img_player      = mlx_xpm_file_to_image(g->mlx_ptr,
                          "assets/neo.xpm", &w, &h);
}

/* render_map: desenha todo o mapa tile por tile */
void render_map(t_game *g)
{
    int x, y;

    y = 0;
    while (y < g->rows)
    {
        x = 0;
        while (x < g->cols)
        {
            mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
                g->img_floor, x * TILE, y * TILE);
            if (g->map[y][x] == '1')
                mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
                    g->img_wall, x * TILE, y * TILE);
            else if (g->map[y][x] == 'C')
                mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
                    g->img_collectible, x * TILE, y * TILE);
            else if (g->map[y][x] == 'E')
                mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
                    g->img_exit, x * TILE, y * TILE);
            else if (g->map[y][x] == 'P')
                mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
                    g->img_player, x * TILE, y * TILE);
            x++;
        }
        y++;
    }
}
