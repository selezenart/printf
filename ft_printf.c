/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:47:42 by aselezen          #+#    #+#             */
/*   Updated: 2026/05/02 16:58:32 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	num;

	if (!ft_is_valid_base(base))
		return ;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		write(1, "-", 1);
		num = -nbr;
	}
	else
		num = nbr;
	if (num >= base_len)
		ft_putnbr_base(num / base_len, base);
	write(1, &base[num % base_len], 1);
}

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