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
      tmp->index = rank;
      tmp = tmp->next;
  }
  return (*stack_a);
}

t_list    *ft_get_runk(t_list *stack_a, int size)
{
   t_list    *tmp;
   int        *array;
   int        i;
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
int ft_calcule_shunk(int size)
{
   if(size <= 130)
       return(13);
   else if(size > 130 && size <= 230)
       return(21);
   return(41);
}
void check_midd_push(t_list *tmp, t_list **stack_a, t_list **stack_b)
{
   int i = 0;
   t_list *head = *stack_b;
   int size = ft_lstsize(*stack_b);
   if (!tmp)
       return ;
   while (head && head->index != tmp->index)
   {
       i++;
       head = head->next;
   }
   while (i <= (size / 2) && i != 0)
   {
       rb(stack_b, ZERO);
       i--;
   }
   while (i > (size / 2) && i < size)
   {
       rrb(stack_b, ZERO);
       i++;
   }
   push_to_a(stack_a, pop_from_b(stack_b));
}
void push_and_rotate(t_list **stack_a, t_list **stack_b, int size_shunk)
{
   t_list *head2;
   while(*stack_a)
   {
       if((*stack_a)->index < ft_lstsize(*stack_b))
       {
           push_to_b(stack_b, pop_from_a(stack_a));
           rb(stack_b, ZERO);
       }
       else if((*stack_a)->index < ft_lstsize(*stack_b) + size_shunk)
           push_to_b(stack_b, pop_from_a(stack_a));
       else
           ra(stack_a, ZERO);
   }
   while (*stack_b)
   {
       head2 = *stack_b;
       while (head2 && head2->index != ft_lstsize(*stack_b) - 1)
           head2 = head2->next;
       check_midd_push(head2, stack_a, stack_b);
   }
}

int main(int ac, char **av)
{
 t_list *stack_a;
 t_list *stack_b;
 stack_b = NULL;
 if (ac < 2)
     error(NULL);
 stack_a = first_stack(&av[1], ac - 1);
 stack_a = ft_get_runk(stack_a, ft_lstsize(stack_a));
 int size_shunk = ft_calcule_shunk(ft_lstsize(stack_a));
 if(ft_lstsize(stack_a) > 5)
       push_and_rotate(&stack_a, &stack_b, size_shunk);
 else 
     sort_three(&stack_a);
 return (0);
}
