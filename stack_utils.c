/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:09:02 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 17:00:52 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"
//More utils for manage stacks
//Count stack nodes
int	stack_len(t_stack *stack)
{
	t_node	*current;
	int		counter;

	current = stack->top;
	counter = 0;
	while (current != NULL)
	{
		current = current->next;
		counter ++;
	}
	return (counter);
}

//Last node
t_node	*last_node(t_stack *stack)
{
	t_node	*last;

	last = stack->top;
	while ((last->next) != NULL)
		last = last->next;
	return (last);
}

//Copy a stack
t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*copy;
	t_node	*current;

	copy = init_stack();
	current = stack->top;
	while (current != NULL)
	{
		push_bottom(copy, current->val);
		current = current->next;
	}
	return (copy);
}
