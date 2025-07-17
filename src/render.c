/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:10:27 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/17 17:40:51 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#define TILE 64

void	load_images(t_game *g)
{
	int	w;
	int	h;

	g->img_floor = mlx_xpm_file_to_image(g->mlx_ptr, "assets/floor.xpm", &w,
			&h);
	g->img_wall = mlx_xpm_file_to_image(g->mlx_ptr, "assets/building.xpm", &w,
			&h);
	g->img_collectible = mlx_xpm_file_to_image(g->mlx_ptr, "assets/pill.xpm",
			&w, &h);
	g->img_exit = mlx_xpm_file_to_image(g->mlx_ptr, "assets/morpheus.xpm", &w,
			&h);
	g->img_player = mlx_xpm_file_to_image(g->mlx_ptr, "assets/neo.xpm", &w, &h);
}

void	render_map(t_game *g)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < g->rows)
	{
		x = 0;
		while (x < g->cols)
		{
			img = g->img_floor;
			if (g->map[y][x] == '1')
				img = g->img_wall;
			if (g->map[y][x] == 'C')
				img = g->img_collectible;
			if (g->map[y][x] == 'E')
				img = g->img_exit;
			if (g->map[y][x] == 'P')
				img = g->img_player;
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, img,
				x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}
