/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:14:45 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/22 14:37:18 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_null_or_empty(const char *str)
{
	if (str == NULL)
		return (1);
	else if (str[0] == '\0')
		return (1);
	else
		return (0);
}

int	skipp_ws_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	long		rs;
	int			sign;

	if (is_null_or_empty(str))
		return (0);
	rs = 0;
	sign = 1;
	i = skipp_ws_sign(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (rs < 0)
		{
			if (sign == -1)
				return (0);
			else if (sign == 1)
				return (-1);
		}
		rs = rs * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(rs * sign));
}
