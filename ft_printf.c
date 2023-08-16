/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:01:42 by emoumni           #+#    #+#             */
/*   Updated: 2023/02/02 04:01:43 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formatss(va_list args, const char form)
{
	int	print_length;

	print_length = 0;
	if (form == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (form == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (form == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (form == 'd' || form == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (form == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (form == 'x' || form == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), form);
	else if (form == '%')
		print_length += ft_printpercent();
	else
		ft_putchar_fd(form, print_length);
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_formatss(args, str[i + 1]);
			i++;
		}
		else
			print_len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
