/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:21:25 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 15:44:28 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Calculate the ra and rra moves needed to be placed at the top of stack A
static void	calculate_moves_in_a(t_stack *a, t_node *node)
{
	int	ra_movs;
	int	rra_movs;

	ra_movs = 0;
	rra_movs = 0;
	if (node->index <= a->size / 2)
		ra_movs = node->index;
	if (node->index > a->size / 2)
		rra_movs = a->size - node->index;
	node->ra_movs = ra_movs;
	node->rra_movs = rra_movs;
}

//Calculate the position in stack B where the node of stack A has to go
static t_node	*calculate_pos_in_b(t_stack *b, t_node *node_a)
{
	t_node	*current_b;
	t_node	*b_last;
	t_node	*min_b;
	t_node	*max_b;

	current_b = b->top;
	b_last = last_node(b);
	min_b = get_min_value_node(b);
	max_b = get_max_value_node(b);
	if (node_a->val < min_b->val || node_a->val > max_b->val)
		return (max_b);
	if (node_a->val > b->top->val && node_a->val < b_last->val)
		return (b->top);
	while (current_b != NULL && current_b->next != NULL)
	{
		if (node_a->val < current_b->val && node_a->val > current_b->next->val)
			return (current_b->next);
		current_b = current_b->next;
	}
	return (b_last);
}

//Calculate the rb and rrb moves needed to be placed at the top of stack B
static void	calculate_moves_in_b(t_stack *b, t_node *node)
{
	int	rb_movs;
	int	rrb_movs;

	rb_movs = 0;
	rrb_movs = 0;
	if (node->index <= b->size / 2)
	{
		rb_movs = node->index;
	}
	else if (node->index > b->size / 2)
	{
		rrb_movs = b->size - node->index;
	}
	node->rb_movs = rb_movs;
	node->rrb_movs = rrb_movs;
}

//Resume ra, rb, rra and rrb movements in rr and rrr
static void	res_moves_a_b(t_node *node_a, t_node *pos_in_b)
{
	int	rr;
	int	rrr;

	rr = min_of_two (node_a->ra_movs, pos_in_b->rb_movs);
	node_a->rr_movs = rr;
	node_a->ra_movs -= rr;
	node_a->rb_movs = pos_in_b->rb_movs - rr;
	rrr = min_of_two (node_a->rra_movs, pos_in_b->rrb_movs);
	node_a->rrr_movs = rrr;
	node_a->rra_movs -= rrr;
	node_a->rrb_movs = pos_in_b->rrb_movs - rrr;
}

//Calculate total movements needed for placing a node from stack A to stack B
void	calculate_total_moves(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*pos_in_b;

	current_a = a->top;
	while (current_a != NULL)
	{
		clear_moves(current_a);
		calculate_moves_in_a(a, current_a);
		pos_in_b = calculate_pos_in_b(b, current_a);
		calculate_moves_in_b(b, pos_in_b);
		res_moves_a_b(current_a, pos_in_b);
		current_a->total_moves += current_a->ra_movs + current_a->rra_movs;
		current_a->total_moves += current_a->rb_movs + current_a->rrb_movs;
		current_a->total_moves += current_a->rr_movs + current_a->rrr_movs;
		current_a = current_a->next;
	}
}
