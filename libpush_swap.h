/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:15:51 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/18 14:07:08 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_SWAP_H
# define LIBPUSH_SWAP_H
# include "my_libft/libft.h"
# include <stdlib.h>

//STRUCTURES
typedef struct s_node
{
	int				val;
	int				index;
	int				ra_movs;
	int				rb_movs;
	int				rr_movs;
	int				rra_movs;
	int				rrb_movs;
	int				rrr_movs;
	int				total_moves;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

//RULES
//rules_swap.c
void	sa(t_stack *a, int mode);
void	sb(t_stack *b, int mode);
void	ss(t_stack *a, t_stack *b, int mode);

//rules_push.c
void	pa(t_stack *a, t_stack *b, int mode);
void	pb(t_stack *a, t_stack *b, int mode);

//rules_rotate.c
void	ra(t_stack *a, int mode);
void	rb(t_stack *b, int mode);
void	rr(t_stack *a, t_stack *b, int mode);

//rules_rev_rotate.c
void	rra(t_stack *a, int mode);
void	rrb(t_stack *b, int mode);
void	rrr(t_stack *a, t_stack *b, int mode);

//MANAGE STACKS
//stack_manager.c
t_stack	*init_stack(void);
t_node	*create_node(int value);
void	push_bottom(t_stack *stack, int value);
void	free_stack(t_stack *stack);
void	free_stacks(t_stack *a, t_stack *b);

//STACK UTILS
//stack_utils.c
int		stack_len(t_stack *stack);
t_node	*last_node(t_stack *stack);
t_stack	*copy_stack(t_stack *stack);
void	clear_moves(t_node *node);

//stack_utils2.c
int		get_min_value(t_stack *stack);
int		get_max_value(t_stack *stack);
t_node	*get_min_value_node(t_stack *stack);
t_node	*get_max_value_node(t_stack *stack);

//OTHER UTILS
//other_utils.c
void	free_split_result(char **split_result);

//MAIN
//main.c
int		main(int argc, char **argv);

//MANAGE ARGS
//args_manager.c
char	**replace_and_split(const char *argv);
int		full_stack_a(int argc, char **argv, t_stack *a);
int		check_mang_args(const char *argv, t_stack *stack);

//CHECK ORDER
//check_order.c
int		check_order(t_stack *stack);

//ALGORITHMS
//sort_small_stack.c
void	sort_2nb(t_stack *stack);
void	sort_3nb(t_stack *a);
void	sort_4nb(t_stack *a, t_stack *b);
void	sort_5nb(t_stack *a, t_stack *b);

//calculate_moves.c
void	calculate_total_moves(t_stack *a, t_stack *b);

//calculate_moves_utils.c
void	clear_moves(t_node *node);
int		min_of_two(int val1, int val2);

//sort_long_stack.c
void	sort_long_stack(t_stack *a, t_stack *b);

#endif