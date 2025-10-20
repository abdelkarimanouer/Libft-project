/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:59:20 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/18 15:18:52 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;
	unsigned char	pc;

	i = 0;
	ps = (unsigned char *) s;
	pc = (unsigned char) c;
	while (i < n)
	{
		if (ps[i] == pc)
			return ((void *)&ps[i]);
		i++;
	}
	return (NULL);
}
