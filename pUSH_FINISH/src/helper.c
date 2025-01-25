#include "push_swap.h"
#include <limits.h>

void    ft_free_array(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}


static int ft_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int ft_atoi(const char *str, t_list *list)
{
    if(!*str || !str)
        error(&list);
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
    if(!(str[i] >= '0' && str[i] <= '9'))
        error(&list);
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = nbr * 10 + (str[i] - '0');
        if (nbr > INT_MAX)
            error(&list);
        i++;
    }
    return ((int)(nbr * sign));
}

