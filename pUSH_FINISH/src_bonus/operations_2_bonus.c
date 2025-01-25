/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylahssin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 01:18:23 by ylahssin          #+#    #+#             */
/*   Updated: 2025/01/25 20:38:49 by ylahssin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    rra(t_list **stack_a)
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
}
void    rrb(t_list **stack_b)
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
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
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
