#include "checker.h"

int is_check(char *arr)
{
    while (*arr)
    {
        if (!(*arr >= '0' && *arr <= '9') && ((*arr != '-' && *arr != '+')))
            return (0);
        arr++;
    }
    return (1);
}

int is_duplicate(t_list *list, int number)
{
    while (list)
    {
        if (list->content == number)
            return (1);
        list = list->next;
    }
    return (0);
}

void    error(t_list **list)
{
    write(2, "Error\n", 6);
    if (list)
        ft_lstclear(list);
    exit(EXIT_FAILURE);
}

t_list    *handle_space_numbers(char *str, t_list *list)
{
    int     j;
    int     num;
    char    **args;
    t_list  *tmp;

    args = ft_split(str, ' ');
    j = 0;
    while (args[j])
    {
        //handle atoi andk fiha mchkill 9adha;
        num = ft_atoi(args[j], list);
        if (!is_check(args[j]) || is_duplicate(list, num))
        {
            ft_free_array(args);
            error(&list);
        }
        tmp = ft_lstnew(num);
        ft_lstadd_back(&list, tmp);
        j++;
    }
    ft_free_array(args);
    return (list);
}

t_list    *first_stack(char **arr, int len_size)
{
    int     i;
    int     num;
    t_list  *list;
    t_list  *tmp;

    i = -1;
    list = NULL;
    while (++i < len_size)
    {
        if (ft_strchr(arr[i], ' '))
        {
            list = handle_space_numbers(arr[i], list);
            continue;
        }
        num = ft_atoi(arr[i], list);
        if ((num == -1 && (ft_strlen(arr[i]) > 2 ||  arr[i][0] == '\0')) || !is_check(arr[i]) || is_duplicate(list, num))
            error(&list);
        tmp = ft_lstnew(num);
        ft_lstadd_back(&list, tmp);
    }
    return (list);
}
