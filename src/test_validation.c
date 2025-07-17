/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:22:02 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/17 17:10:26 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	check_args(argc, argv);
	map = read_map(argv[1]);
	validate_rectangle_and_walls(map);
	printf("Rectangle & walls OK\n");
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}
