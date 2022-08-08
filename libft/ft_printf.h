/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:47:39 by a          #+#    #+#             */
/*   Updated: 2022/05/16 18:47:41 by a         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *s, ...);
int		bul(char *s, va_list *args);
int		print_char(char c);
int		string_yazdir(char *str);
int		sayi_yazdir(int i);
int		unsigned_yazdir(unsigned int nb);
int		hex_yazdir(unsigned long int nb, int s);
#endif
