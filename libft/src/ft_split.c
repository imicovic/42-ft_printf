/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:13:20 by imicovic          #+#    #+#             */
/*   Updated: 2024/06/17 07:52:51 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static size_t	d_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	ft_free(char **ptr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(ptr[i]);
	free(ptr);
}

static int	ft_copy(char **ptr, int index, const char *s, char c)
{
	int	word_len;

	if (!ft_strchr(s, c))
		word_len = ft_strlen(s);
	else
		word_len = ft_strchr(s, c) - s;
	ptr[index] = ft_substr(s, 0, word_len);
	return (word_len);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	word_len;
	int		i;

	ptr = (char **)malloc((d_count(s, c) + 1) * sizeof(char *));
	if (!s || !ptr)
		return (0);
	i = -1;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_len = ft_copy(ptr, ++i, s, c);
			if (!ptr[i])
			{
				ft_free(ptr, i);
				return (NULL);
			}
			s += word_len;
		}
	}
	ptr[++i] = NULL;
	return (ptr);
}
