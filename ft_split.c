/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:10:27 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/19 10:17:00 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getsize(char const *s, char c)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (c != s[i])
		{
			size++;
			while (c != s[i] && s[i])
				i++;
		}
		else
			i++;
	}
	return (size);
}

static char	*add_str(const char *s, size_t start, size_t end)
{
	size_t		i;
	char		*copy;
	size_t		len;

	i = 0;
	len = end - start;
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	while (i < len)
	{
		copy[i] = s[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static size_t	skip(size_t i, char c, char const *s)
{
	while (c != s[i] && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		index;
	size_t	start;
	char	**arr;

	if (!s)
		return (NULL);
	i = 0;
	index = 0;
	arr = malloc(sizeof(char *) * (getsize(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		if (c != s[i])
		{
			start = i;
			i = skip(i, c, s);
			arr[index++] = add_str(s, start, i);
		}
		else
			i++;
	}
	arr[index] = NULL;
	return (arr);
}
