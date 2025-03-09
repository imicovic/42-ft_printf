/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:22:43 by imicovic          #+#    #+#             */
/*   Updated: 2024/06/17 07:04:27 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

static int	ft_numlen(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

char	*ft_print_hex(unsigned int num, const char format)
{
	int		len;
	char	*hex_chars;
	char	*buffer;

	if (format == 'x')
		hex_chars = "0123456789abcdef\0";
	else
		hex_chars = "0123456789ABCDEF\0";
	len = ft_numlen(num);
	buffer = malloc(len + 1);
	buffer[len] = '\0';
	if (num == 0)
		buffer[0] = '0';
	while (num != 0)
	{
		buffer[--len] = hex_chars[num % 16];
		num /= 16;
	}
	return (buffer);
}
