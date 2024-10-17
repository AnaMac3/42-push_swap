/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:46:00 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 17:32:42 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Functions to sort small stacks
//Stacks with 2 elements
void	sort_2nb(t_stack *a)
{
	t_node	*node;

	node = a->top;
	if (node->val > node->next->val)
		sa(a, 0);
}

//Stacks with 3 elements
//Only get into sort_3nb if check_order(stack) == 0
void	sort_3nb(t_stack *a)
{
	t_node	*node;
	int		min;
	int		max;

	node = a->top;
	min = get_min_value(a);
	max = get_max_value(a);
	if (min == node->val)
	{
		rra(a, 0);
		sa(a, 0);
	}
	else if (max == node->val)
	{
		ra(a, 0);
		if (check_order(a) == 0)
			sa(a, 0);
	}
	else
	{
		if (node->next->val == max)
			rra(a, 0);
		else
			sa(a, 0);
	}
}

//Stacks with 4 elements
void	sort_4nb(t_stack *a, t_stack *b)
{
	pb(a, b);
	if (check_order(a) == 0)
		sort_3nb(a);
	if (b->top->val < a->top->val)
		pa(a, b);
	else if (b->top->val > last_node(a)->val)
	{
		pa(a, b);
		ra(a, 0);
	}
	else if (b->top->val < a->top->next->val)
	{
		pa(a, b);
		sa(a, 0);
	}
	else if (b->top->val > a->top->next->val)
	{
		rra(a, 0);
		pa(a, b);
		ra(a, 0);
		ra(a, 0);
	}
}

//Stack with 5 elements
void	sort_5nb(t_stack *a, t_stack *b)
{
	pb(a, b);
	sort_4nb(a, b);
	if (b->top->val < a->top->next->val || b->top->val > last_node(a)->val)
	{
		pa(a, b);
		if (a->top->val > last_node(a)->val)
			ra(a, 0);
		else if (a->top->val > a->top->next->val)
			sa(a, 0);
	}
	else if (b->top->val < a->top->next->next->val)
	{
		ra(a, 0);
		pa(a, b);
		sa(a, 0);
		rra(a, 0);
	}
	else if (b->top->val < last_node(a)->val)
	{
		rra(a, 0);
		pa(a, b);
		ra(a, 0);
		ra(a, 0);
	}
}
