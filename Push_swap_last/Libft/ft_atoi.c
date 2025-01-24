/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <ylahssin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:31:28 by ylahssin          #+#    #+#             */
/*   Updated: 2025/01/24 19:19:50 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include "libft.h"

static int ft_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    long long nbr = 0;

    while (str[i] && ft_space(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = nbr * 10 + (str[i] - '0');
        if (nbr > INT_MAX)
            return (-1);
        i++;
    }
    return ((int)(nbr * sign));
}

