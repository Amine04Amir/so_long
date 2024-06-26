/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:27:51 by mamir             #+#    #+#             */
/*   Updated: 2024/05/07 16:20:23 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char *str, va_list list)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (str[i] == '%')
		count = ft_putchar('%');
	else if (str[i] == 'c')
		count = ft_putchar(va_arg(list, int));
	else if (str[i] == 's')
		count = ft_putstr(va_arg(list, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count = ft_putnbr(va_arg(list, int));
	else if (str[i] == 'p')
	{
		count = ft_putstr("0x");
		count += ft_putpointer(va_arg(list, unsigned long));
	}
	else if (str[i] == 'u')
		count = ft_punsigned(va_arg(list, unsigned int));
	else if (str[i] == 'x')
		count = ft_phexa(va_arg(list, unsigned int));
	else if (str[i] == 'X')
		count = ft_phexau(va_arg(list, unsigned int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	list;

	va_start(list, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			else
			{
				count += ft_check(&str[i + 1], list);
				i++;
			}
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (count);
}
