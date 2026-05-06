/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:58:11 by aselezen          #+#    #+#             */
/*   Updated: 2026/05/04 15:01:03 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"

void ft_putnumber_decimal(int numb)
{
    char *alphabeth;
    
    alphabeth = "0123456789";
    ft_putnumber_base(numb, alphabeth);
}