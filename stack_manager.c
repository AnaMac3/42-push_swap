/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:23:52 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 17:00:20 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"
//Initialize stack
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

//Create a node
t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

//Add a node at the top of the stack
void	push_bottom(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*last;

	new_node = create_node(value);
	if (stack->top == NULL)
		stack->top = new_node;
	else
	{
		last = last_node(stack);
		last->next = new_node;
	}
	stack->size ++;
}

//Free the stack
void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

//Free two stacks
void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}
