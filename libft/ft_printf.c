/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:47:30 by a          #+#    #+#             */
/*   Updated: 2022/05/16 18:47:32 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags(char s)
{
	if (s != 'c' && s != 's' && s != 'p' && s != 'd' && s != 'i' && s != 'u'
		&& s != 'x' && s != 'X' && s != '%')
		return (0);
	return (1);
}

int	print_char(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	bul(char *s, va_list *args)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += print_char(va_arg(*args, int));
	if (*s == 's')
		count += string_yazdir(va_arg(*args, char *));
	if (*s == 'p')
	{
		count += write(1, "0x", 2);
		count += hex_yazdir(va_arg(*args, unsigned long int), 1);
	}
	if (*s == 'd' || *s == 'i')
		count += sayi_yazdir(va_arg(*args, int));
	if (*s == 'u')
		count += unsigned_yazdir(va_arg(*args, unsigned int));
	if (*s == 'x')
		count += hex_yazdir(va_arg(*args, unsigned int), 1);
	if (*s == 'X')
		count += hex_yazdir (va_arg(*args, unsigned int), 2);
	if (*s == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(char const *s, ...)
{
	va_list		ap;
	int			i;
	int			count;

	i = -0;
	count = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] != '%')
			count += write(1, &s[i], 1);
		if (s[i] == '%')
		{
			count += bul ((char *)(s + i + 1), &ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
