/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:47:42 by aselezen          #+#    #+#             */
/*   Updated: 2026/05/04 14:57:03 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	char	*str;
    char    *set_d;

    
    set_d = "0123456789";
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == 'd')
			{
				int num = va_arg(args, int);
				ft_putnbr_base(num, set_d);
				
				if (num == 0)
					count++;
				else if (num < 0)
				{
					count++;
					num = -num;
				}
				int temp = num;
				while (temp > 0)
				{
					count++;
					temp /= 10;
				}
			}
			else if (*format == '%')
			{
				ft_putchar('%');
				count++;
			}
			// TODO Add other formats here later, e.g., else if (*format == 's') { str = va_arg(args, char*); ft_putstr(str); count += ft_strlen(str); }
			else
			{
				// For now, just print the % and the char
				ft_putchar('%');
				ft_putchar(*format);
				count += 2;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}

int	ft_strlen(char *str)
{
	int len = 0;
	while (*str++)
		len++;
	return (len);
}

int	main(void)
{
	ft_printf("Hello %d world!\n", 42);
	return (0);
}