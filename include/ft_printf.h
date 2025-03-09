/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:30:05 by imicovic          #+#    #+#             */
/*   Updated: 2024/06/18 00:30:06 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

char	*ft_print_hex(unsigned int num, const char format);
int		ft_print_ptr(unsigned long p);
int		ft_print_str(char *s);
int		ft_print_char(int c);
int		ft_printf(const char *fmt, ...);
int		ft_print_int(int x);
int		ft_print_uint(unsigned int x);

#endif
