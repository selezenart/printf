/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:52:55 by aselezen          #+#    #+#             */
/*   Updated: 2026/05/04 14:52:56 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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