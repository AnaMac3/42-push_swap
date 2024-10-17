/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:15:00 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 17:01:37 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Find min value
int	get_min_value(t_stack *stack)
{
	t_node	*current;
	t_node	*min;

	current = stack->top;
	min = stack->top;
	while (current != NULL)
	{
		if (current->val < min->val)
			min = current;
		current = current->next;
	}
	return (min->val);
}

//Find max value
int	get_max_value(t_stack *stack)
{
	t_node	*current;
	t_node	*max;

	current = stack->top;
	max = stack->top;
	while (current != NULL)
	{
		if (current->val > max->val)
			max = current;
		current = current->next;
	}
	return (max->val);
}

//Find min value pos
t_node	*get_min_value_node(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	current = stack->top;
	min_node = current;
	while (current != NULL)
	{
		if (current->val < min_node->val)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

//Find max value pos
t_node	*get_max_value_node(t_stack *stack)
{
	t_node	*current;
	t_node	*max_node;

	current = stack->top;
	max_node = current;
	while (current != NULL)
	{
		if (current->val > max_node->val)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}
