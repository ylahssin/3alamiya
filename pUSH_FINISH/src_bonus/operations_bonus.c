#include "checker.h"

void    push_to_a(t_list **stack_a, t_list *node)
{
    if (!stack_a || !node)
        return ;
    if (*stack_a)
        node->next = *stack_a;
    else
        node->next = NULL;
    *stack_a = node;
    write(1, "pa\n", 3);
}

void    push_to_b(t_list **stack_b, t_list *node)
{
    if (!stack_b || !node)
        return ;
    if (*stack_b)
        node->next = *stack_b;
    else
        node->next = NULL;
    *stack_b = node;
    write(1, "pb\n", 3);
}

void    ra(t_list **stack_a)
{
    t_list  *first;
    t_list  *last;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    first = *stack_a;
    last = *stack_a;
    while (last->next)
        last = last->next;
    *stack_a = first->next;
    first->next = NULL;
    last->next = first;
}

void    rb(t_list **stack_b)
{
    t_list  *first;
    t_list  *last;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    first = *stack_b;
    last = *stack_b;
    while (last->next)
        last = last->next;
    *stack_b = first->next;
    first->next = NULL;
    last->next = first;
}
void    rr(t_list **stack_a, t_list **stack_b)
{
    if (!stack_a || !stack_b || !*stack_a || !*stack_b)
        return ;
    ra(stack_a);
    rb(stack_b);
}
