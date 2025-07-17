/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:01:33 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/17 17:17:52 by fsuguiur         ###   ########.fr       */
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

void	validate_rectangle_and_walls(char **map)
{
	int	width;
	int	i;
	int	j;

	width = ft_strlen(map[0]);
	i = 0;
	while (map[++i])
	{
		if ((int)ft_strlen(map[i]) != width)
			erro("Map is not rectangular");
	}
	j = 0;
	while (j < width)
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			erro("Map walls must be closed");
		j++;
	}
	i = 0;
	while (map[++i] && map[i + 1])
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			erro("Map walls must be closed");
	}
}
