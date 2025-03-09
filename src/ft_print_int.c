/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:49:48 by imicovic          #+#    #+#             */
/*   Updated: 2024/06/16 21:54:34 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_print_int(int x)
{
	char	*s;
	int		len;

	s = ft_itoa(x);
	len = ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}
