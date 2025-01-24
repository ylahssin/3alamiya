#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../Libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
enum Numbers 
{ 
  POSITIVE = 1, 
  NEGATIVE = -1, 
  ZERO = 0 
};
typedef struct cost
{
    int cost_a;
    int cost_b;
}t_cost;
typedef struct s_number
{
  int less_number_position;
  int big_number_position;
  int big_num_cost;
  int less_num_cost;
}t_number;
typedef struct s_prev
{
    int first;
    int last;
    int midd;
    int max;
    int min;
} t_prev;
void    ra(t_list **stack_a, int is_check);
void    rb(t_list **stack_b, int is_check);
void    rr(t_list **stack_a, t_list **stack_b, int is_check);
void    rra(t_list **stack_a, int is_check);
void    rrb(t_list **stack_b, int is_check);
void    rrr(t_list **stack_a, t_list **stack_b, int is_check);
void    push_to_a(t_list **stack_a, t_list *top);
void    push_to_b(t_list **stack_b, t_list *top);
t_list *pop_from_b(t_list **stack_b);
t_list *pop_from_a(t_list **stack_a);
t_list    *first_stack(char **arr, int len_size);
t_list    *handle_space_numbers(char *str, t_list *list);
void    error(t_list **list);
int is_duplicate(t_list *list, int number);
int is_check(char *arr);
void    ft_free_array(char **arr);

#endif
