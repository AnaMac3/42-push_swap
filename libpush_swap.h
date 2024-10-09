/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:15:51 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/09 09:37:24 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_SWAP_H
# define LIBPUSH_SWAP_H
# include "my_libft/libft.h"
# include <stdlib.h>

//STRUCTURES
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

//RULES
//rules_swap.c
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

//rules_push.c
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

//rules_rotate.c
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

//rules_rev_rotate.c
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//MANAGE STACKS
//stack_manager.c
t_stack	*init_stack(void);
t_node	*create_node(int value);
void	push(t_stack *stack, int value);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);

#endif