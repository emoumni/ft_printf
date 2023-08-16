/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:06:44 by emoumni           #+#    #+#             */
/*   Updated: 2023/02/02 04:06:45 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char form)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, form);
		ft_put_hex(num % 16, form);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (form == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (form == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char form)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, form);
	return (ft_hex_len(num));
}
