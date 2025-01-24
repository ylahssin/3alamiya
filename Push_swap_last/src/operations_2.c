/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 01:18:23 by ylahssin          #+#    #+#             */
/*   Updated: 2025/01/24 01:16:45 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_list **stack_a, int is_check)
{
    t_list  *last;
    t_list *prev;
    last = *stack_a;
    prev = NULL;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if(prev)
        prev->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    if(!is_check)
        write(1, "rra\n", 4);
}
void    rrb(t_list **stack_b, int is_check)
{
    t_list  *last;
    t_list *prev;
    last = *stack_b;
    prev = NULL;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if(prev)
        prev->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    if(!is_check)
        write(1, "rrb\n", 4);
}

void    rrr(t_list **stack_a, t_list **stack_b, int is_check)
{
    rra(stack_a, is_check);
    rrb(stack_b, is_check);
    write(1, "rrr\n", 4);
}
t_list *pop_from_a(t_list **stack_a)
{
    t_list *top;
    
    if (!stack_a || !*stack_a)
        return (NULL);
    top = *stack_a;
    *stack_a = (*stack_a)->next;
    top->next = NULL;
    return (top);
}
t_list *pop_from_b(t_list **stack_b)
{
    t_list *top;

    if (!stack_b || !*stack_b)
        return (NULL);
    top = *stack_b;
    *stack_b = (*stack_b)->next;
    top->next = NULL;
    return (top);
}
