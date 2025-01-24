#include "push_swap.h"

void sa(t_list *a)
{
   int swap = a->content;
   a->content = a->next->content;
   a->next->content = swap;
   write(1, "sa\n", 3);
}

void sort_int_tab(int *tab, unsigned int size)
{
  unsigned int i;
  unsigned int j;
  int temp;
  i = 0;
  while (i < size)
  {
      j = 0;
      while (j < size - 1)
      {
          if (tab[j] > tab[j + 1])
          {
              temp = tab[j];
              tab[j] = tab[j + 1];
              tab[j + 1] = temp;
          }
          j++;
      }
      i++;
  }
}

t_list *change_stack_a(t_list **stack_a, int *arr, int size)
{
   t_list *tmp;
   int i;
   int rank;

   tmp = *stack_a;
   while (tmp)
   {
       i = 0;
       rank = 0;
       while (i < size)
       {
           if (tmp->content > arr[i])
               rank++;
           i++;
       }
       tmp->content = rank;
       tmp = tmp->next;
   }
   return (*stack_a);
}

t_list	*ft_get_runk(t_list *stack_a, int size)
{
    t_list	*tmp;
    int		*array;
    int		i;

    if (!stack_a || size <= 0 || !(array = malloc(sizeof(int) * size)))
        return (NULL);
    tmp = stack_a;
    i = 0;
    while (tmp)
    {
        array[i++] = tmp->content;
        tmp = tmp->next;
    }
    sort_int_tab(array, (unsigned int)size);
    stack_a = change_stack_a(&stack_a, array, size);
    free(array);
    return (stack_a);
}

void sort_three(t_list **a)
{
   if ((*a)->content > (*a)->next->content && (*a)->next->content < (*a)->next->next->content
       && (*a)->content < (*a)->next->next->content)
       sa(*a);
   else if ((*a)->content > (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
   {
       sa(*a);
       rra(a, ZERO); 
   }
   else if ((*a)->content > (*a)->next->content && (*a)->next->content < (*a)->next->next->content
       && (*a)->content > (*a)->next->next->content)
       ra(a, ZERO);
   else if ((*a)->content < (*a)->next->content && (*a)->next->content > (*a)->next->next->content
       && (*a)->content < (*a)->next->next->content)
   {
       sa(*a);
       ra(a, ZERO);
   }
   else if ((*a)->content < (*a)->next->content && (*a)->next->content > (*a)->next->next->content
       && (*a)->content > (*a)->next->next->content)
       rra(a, ZERO);
}


int main(int ac, char **av)
{
  t_list *stack_a;
  t_list *stack_b;
  stack_b = NULL;
  (void)stack_b;
  if (ac < 2)
      error(NULL);
  stack_a = first_stack(&av[1], ac - 1);
  stack_a = ft_get_runk(stack_a, ft_lstsize(stack_a));
  //ft_pre_sort(&stack_a, &stack_b, ft_lstsize(stack_a) / 2);
  return (0);
}
