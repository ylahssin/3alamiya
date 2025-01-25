#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
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
void print_check_ok(char *check, t_list **stack_a)
{
    if (stack_a)
        ft_lstclear(stack_a);
    write(1, check, 3);
    exit(1);
}

void print_check_ko(char *check, t_list **stack_a)
{
    if (stack_a)
        ft_lstclear(stack_a);
    write(1, check, 3);
    exit(1);
}

int check_operation(char *line, t_list **stack_a, t_list **stack_b)
{
    if (!ft_strcmp(line, "sa\n"))
        return (sa(*stack_a), POSITIVE);
     if (!ft_strcmp(line, "sb\n"))
        return (sb(*stack_b), POSITIVE);
    else if (!ft_strcmp(line, "ss\n"))
        return (ss(*stack_a, *stack_b), POSITIVE);
    else if (!ft_strcmp(line, "ra\n"))
        return (ra(stack_a), POSITIVE);
    else if (!ft_strcmp(line, "rb\n"))
        return (rb(stack_b), POSITIVE);
    else if (!ft_strcmp(line, "rr\n"))
        return (rr(stack_a, stack_b), POSITIVE); 
    else if (!ft_strcmp(line, "rra\n"))
        return (rra(stack_a), POSITIVE);
    else if (!ft_strcmp(line, "rrb\n"))
        return (rrb(stack_b), POSITIVE);
    else if (!ft_strcmp(line, "rrr\n"))
        return (rrr(stack_a, stack_b), POSITIVE);
    else if (!ft_strcmp(line, "pa\n"))
        return (push_to_a(stack_a, pop_from_b(stack_b)), POSITIVE);
    else if (!ft_strcmp(line, "pb\n"))
        return (push_to_b(stack_b, pop_from_a(stack_a)), POSITIVE);
    return (ZERO);
}

int is_sorting(t_list **stack_a)
{
    t_list *tmp = *stack_a;
    if (!tmp || !tmp->next)
        return (POSITIVE);
    while (tmp->next)
    {
        if (tmp->content > tmp->next->content)
            return (ZERO);
        tmp = tmp->next;
    }
    return (1);
}

void read_from_checker(t_list **stack_a, t_list **stack_b)
{
    char *line;

    if (is_sorting(stack_a))
        print_check_ok(CHECK_OK, stack_a);

    while (1)
    {
        line = get_next_line(STDIN_FILENO);
        if (!line)
            break;
        if (check_operation(line, stack_a, stack_b))
        {
            free(line);
            continue;
        }
        free(line);
        break;
    }

    if (line)
        free(line);

    if (is_sorting(stack_a))
        print_check_ok(CHECK_OK, stack_a);

    print_check_ko(CHECK_KO, stack_a);
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
    read_from_checker(&stack_a, &stack_b);
    return (0);
}

