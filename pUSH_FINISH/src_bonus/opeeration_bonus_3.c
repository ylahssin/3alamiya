#include "checker.h"

void sa(t_list *a)
{
    int swap = a->content;
    a->content = a->next->content;
    a->next->content = swap;
}

void sb(t_list *b)
{
    int swap = b->content;
    b->content = b->next->content;
    b->next->content = swap;
}

void ss(t_list *stack_a, t_list *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}
