/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:05:53 by emoumni           #+#    #+#             */
/*   Updated: 2023/02/02 04:05:55 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(size_t numb)
{
	int	len;

	len = 0;
	while (numb != 0)
	{
		len++;
		numb = numb / 16;
	}
	return (len);
}

void	ft_put_ptr(size_t numb)
{
	if (numb >= 16)
	{
		ft_put_ptr(numb / 16);
		ft_put_ptr(numb % 16);
	}
	else
	{
		if (numb <= 9)
			ft_putchar_fd((numb + '0'), 1);
		else
			ft_putchar_fd((numb - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
