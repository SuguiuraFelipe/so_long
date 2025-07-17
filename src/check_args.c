/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:58:14 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/17 17:09:57 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] < str2[i])
			return (-1);
		else if (str1[i] > str2[i])
			return (1);
		if (str1[i] == '\0' || str2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

void	check_args(int ac, char **av)
{
	int	len;

	if (ac != 2)
		write(1, "invalid ac\n", 12);
	len = ft_strlen(av[1]);
	if (len < 5)
		write(1, "Map file must be at least 4 characters\n", 40);
	if (ft_strncmp(av[1] + len - 4, ".ber", 4) != 0)
		write(1, "Map file must end in .ber\n", 27);
}
