/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdata_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:52:55 by aselezen          #+#    #+#             */
/*   Updated: 2026/05/14 15:11:52 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	counter;

	if (!str)
		return (ft_putstr("(null)"));
	counter = 0;
	while (*str)
	{
		ft_putchar(*str);
		str++;
		counter++;
	}
	return (counter);
}

int	ft_putnbr_base(long nbr, char *base)
{
	unsigned int	base_len;
	long			num;
	int				count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		num = -nbr;
	}
	else
		num = nbr;
	if (num >= base_len)
		count += ft_putnbr_base(num / base_len, base);
	count += write(1, &base[num % base_len], 1);
	return (count);
}

int	ft_putnbr_base_unsigned(unsigned long nbr, char *base)
{
	unsigned int	base_len;
	int				count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
		count += ft_putnbr_base_unsigned(nbr / base_len, base);
	count += write(1, &base[nbr % base_len], 1);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_putnbr_base_unsigned((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
