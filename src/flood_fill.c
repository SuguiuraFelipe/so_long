/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:53:10 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/17 17:06:01 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	erro(char *msg)
{
	write(2, "Error\n", 6);
	while (*msg)
		write(2, msg++, 1);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

static void	find_player(char **map, int *px, int *py)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	flood_fill(char **m, int x, int y)
{
	if (m[y][x] == '1' || m[y][x] == 'F')
		return ;
	m[y][x] = 'F';
	flood_fill(m, x + 1, y);
	flood_fill(m, x - 1, y);
	flood_fill(m, x, y + 1);
	flood_fill(m, x, y - 1);
}

void	validate_paths(char **map)
{
	char	**tmp;
	int		px;
	int		py;
	int		i;
	int		j;

	tmp = dup_map(map);
	find_player(tmp, &px, &py);
	flood_fill(tmp, px, py);
	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'C' || tmp[i][j] == 'E')
				erro("Map is not solvable");
			j++;
		}
		i++;
	}
	free_map(tmp);
}
