/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:17:50 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/21 13:43:31 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Assign indexes to the nodes of the stack
static void	assign_index(t_stack *stack)
{
	t_node	*current;
	int		index;

	current = stack->top;
	index = 0;
	while (current != NULL)
	{
		current->index = index;
		current = current->next;
		index ++;
	}
}

//Find the node from stack A that needs less movements to be placed in stack B
static t_node	*find_best_node_to_move(t_stack *a)
{
	t_node	*current;
	t_node	*best_node;
	int		min_moves;

	current = a->top;
	best_node = current;
	min_moves = current->total_moves;
	while (current != NULL)
	{
		if (current->total_moves < min_moves)
		{
			min_moves = current->total_moves;
			best_node = current;
		}
		current = current->next;
	}
	return (best_node);
}

//Perform the calculated movements
static void	do_calculated_moves(t_node *best_node, t_stack *a, t_stack *b)
{
	while (best_node->rr_movs --)
		rr(a, b, 0);
	while (best_node->rrr_movs --)
		rrr(a, b, 0);
	while (best_node->ra_movs --)
		ra(a, 0);
	while (best_node->rra_movs --)
		rra(a, 0);
	while (best_node->rb_movs --)
		rb(b, 0);
	while (best_node->rrb_movs --)
		rrb(b, 0);
}

//Move the max value of stack B to the top
static void	max_value_to_top(t_stack *b)
{
	t_node	*b_max;

	b_max = get_max_value_node(b);
	while (b->top->val != get_max_value(b))
	{
		if (b_max->index <= b->size / 2)
		{
			while (b_max->index > 0)
			{
				rb(b, 0);
				b_max->index --;
			}
		}
		else if (b_max->index > b->size / 2)
		{
			while ((b->size - b_max->index) > 0)
			{
				rrb(b, 0);
				b_max->index ++;
			}
		}
	}
}

//Sort long stack
void	sort_long_stack(t_stack *a, t_stack *b)
{
	t_node	*best_node;

	pb(a, b, 0);
	pb(a, b, 0);
	while (a->size > 0)
	{
		assign_index(a);
		assign_index(b);
		calculate_total_moves(a, b);
		best_node = find_best_node_to_move(a);
		do_calculated_moves(best_node, a, b);
		pb(a, b, 0);
	}
	assign_index(b);
	if (b->top->val != get_max_value(b))
		max_value_to_top(b);
	while (b->size > 0)
		pa(a, b, 0);
}
