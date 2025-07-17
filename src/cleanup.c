/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:35:26 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/17 17:18:44 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_game(t_game *g)
{
	int	y;

	y = 0;
	while (g->map[y])
		free(g->map[y++]);
	free(g->map);
	mlx_destroy_image(g->mlx_ptr, g->img_floor);
	mlx_destroy_image(g->mlx_ptr, g->img_wall);
	mlx_destroy_image(g->mlx_ptr, g->img_player);
	mlx_destroy_image(g->mlx_ptr, g->img_collectible);
	mlx_destroy_image(g->mlx_ptr, g->img_exit);
	mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	exit(EXIT_SUCCESS);
}
