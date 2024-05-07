/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:25:44 by mamir             #+#    #+#             */
/*   Updated: 2023/12/13 22:25:47 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_strlen(char *str);
int	ft_putnbr(int n);
int	ft_putpointer(unsigned long n);
int	ft_punsigned(unsigned int n);
int	ft_phexau(unsigned int n);
int	ft_phexa(unsigned int n);

#endif
