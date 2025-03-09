/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:38:49 by imicovic          #+#    #+#             */
/*   Updated: 2024/06/17 07:18:12 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

static int	ft_num_len(unsigned long num)
{
	int	len;

	len = 2;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

int	ft_print_ptr(unsigned long p)
{
	char			*buffer;
	char			*hex_chars;
	int				len;

	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	hex_chars = "0123456789abcdef\0";
	len = ft_num_len(p);
	buffer = malloc(len + 1);
	buffer[0] = '0';
	buffer[1] = 'x';
	buffer[len] = '\0';
	while (p != 0)
	{
		buffer[--len] = hex_chars[p % 16];
		p /= 16;
	}
	len = ft_strlen(buffer);
	write(1, buffer, len);
	free(buffer);
	return (len);
}
