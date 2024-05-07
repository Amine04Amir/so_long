/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:28:22 by mamir             #+#    #+#             */
/*   Updated: 2023/12/17 12:28:27 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_punsigned(unsigned int n)
{
	int		count;

	count = 0;
	if (n > 9)
	{
		count += ft_punsigned(n / 10);
		count += ft_punsigned(n % 10);
	}
	else
		count += ft_putchar(n +48);
	return (count);
}

int	ft_phexa(unsigned int n)
{
	int		count;
	char	*p;

	p = "0123456789abcdef";
	count = 0;
	if (n > 15)
	{
		count += ft_phexa(n / 16);
		count += ft_phexa(n % 16);
	}
	else
		count += ft_putchar(p[n]);
	return (count);
}

int	ft_phexau(unsigned int n)
{
	int		count;
	char	*p;

	p = "0123456789ABCDEF";
	count = 0;
	if (n > 15)
	{
		count += ft_phexau(n / 16);
		count += ft_phexau(n % 16);
	}
	else
		count += ft_putchar(p[n]);
	return (count);
}
