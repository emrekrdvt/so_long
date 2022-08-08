/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yazdir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:48:32 by a          #+#    #+#             */
/*   Updated: 2022/05/16 18:48:33 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_yazdir(unsigned long int nb, int s)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += hex_yazdir(nb / 16, s);
		len += hex_yazdir(nb % 16, s);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_char(nb + 48);
		else
		{
			if (s == 1)
				len += print_char(nb + 87);
			else
				len += print_char(nb + 55);
		}
	}
	return (len);
}

int	string_yazdir(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

int	sayi_yazdir(int nb)
{
	long long	n;
	int			len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += sayi_yazdir(n / 10);
		len += sayi_yazdir(n % 10);
	}
	if (n < 10)
		len += print_char(n + 48);
	return (len);
}

int	unsigned_yazdir(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += unsigned_yazdir(nb / 10);
		len += unsigned_yazdir(nb % 10);
	}
	if (nb < 10)
		len += print_char(nb + 48);
	return (len);
}
