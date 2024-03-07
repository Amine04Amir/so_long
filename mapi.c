/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:17:07 by mamir             #+#    #+#             */
/*   Updated: 2024/03/05 19:17:09 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"
# include <stdio.h>

int ft_countline(char *path)
{
	int fd;
	int	i;
	char *str;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return 0;
	str = get_next_line(fd);
	i = 0;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close (fd);
	return (i);
}

int main (int ac, char **av)
{
	if (ac != 2)
		return 0;
	t_data map_data;
	map_data.map_dim[0] = (int *)malloc(sizeof(int));
	if (!map_data.map_dim[0])
		return 0;
	*(map_data.map_dim[0]) = ft_countline(av[1]);
	printf("%d\n", ft_countline(av[1]));
}	
