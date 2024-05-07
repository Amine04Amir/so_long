/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:28:08 by mamir             #+#    #+#             */
/*   Updated: 2023/12/17 12:28:13 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		count += ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
		count += ft_putnbr(n);
	}
	else if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}

int	ft_putpointer(unsigned long n)
{
	int		count;
	char	*p;

	p = "0123456789abcdef";
	count = 0;
	if (n > 15)
	{
		count += ft_putpointer(n / 16);
		count += ft_putpointer(n % 16);
	}
	else
		count += ft_putchar(p[n]);
	return (count);
}
