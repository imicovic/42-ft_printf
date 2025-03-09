/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:52:35 by imicovic          #+#    #+#             */
/*   Updated: 2024/06/17 07:25:50 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

static int	ft_numlen(unsigned int x)
{
	int	len;

	len = 0;
	if (x == 0)
		len = 1;
	while (x != 0)
	{
		len++;
		x /= 10;
	}
	return (len);
}

static char	*ft_utoa(unsigned int x)
{
	char	*s;
	int		len;

	len = ft_numlen(x);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (x == 0)
		s[0] = '0';
	while (x != 0)
	{
		s[--len] = x % 10 + '0';
		x /= 10;
	}
	return (s);
}

int	ft_print_uint(unsigned int x)
{
	char	*s;
	int		len;

	s = ft_utoa(x);
	len = ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}
