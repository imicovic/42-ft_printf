/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:28:27 by imicovic          #+#    #+#             */
/*   Updated: 2025/03/09 20:58:33 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

static int	ft_format(va_list args, const char format)
{
	int		count;
	char	*s;

	count = 0;
	if (format == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (format == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (format == 'u')
		count += ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'd' || format == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (format == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'x' || format == 'X')
	{
		s = ft_print_hex(va_arg(args, unsigned int), format);
		write(1, s, ft_strlen(s));
		count += ft_strlen(s);
		free(s);
	}
	else if (format == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = -1;
	count = 0;
	va_start(args, fmt);
	while (fmt[++i])
	{
		if (fmt[i] != '%')
		{
			write(1, &fmt[i], 1);
			count++;
		}
		else if (fmt[i] == '%' && fmt[i + 1] != '\0')
		{
			count += ft_format(args, fmt[i + 1]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
