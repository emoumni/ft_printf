/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:05:02 by emoumni           #+#    #+#             */
/*   Updated: 2023/02/02 04:05:04 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned	int numb)
{
	int	len;

	len = 0;
	while (numb != 0)
	{
		len++;
		numb = numb / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_len;
	char	*num;

	print_len = 0;
	if (n == 0)
		print_len += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print_len += ft_printstr(num);
		free(num);
	}
	return (print_len);
}
