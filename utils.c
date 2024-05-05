/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:51:23 by mamir             #+#    #+#             */
/*   Updated: 2024/05/05 21:53:10 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	while_check(t_data *data, char *str, char *path)
{
	int	j;
	int	i;
	int	fd;

	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str != NULL)
	{
		j = 0;
		if (i == data->map_dim[0] - 1)
		{
			while (str[j] != '\0')
			{
				if (str[j] != '1')
					ft_error();
				j++;
			}
		}
		str = get_next_line(fd);
		i++;
	}
}
