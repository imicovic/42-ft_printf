/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:26:53 by imicovic          #+#    #+#             */
/*   Updated: 2024/06/17 07:52:51 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s;
	i = -1;
	while (++i < n)
		ptr[i] = '\0';
}
