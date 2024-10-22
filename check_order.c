/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:26:38 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/21 13:44:20 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"
//Check if the numbers of the stack are in correct order
//0 -> is not sorted
//1 -> is sorted with min value at the top and max value at the end
int	check_order(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL && current->next != NULL)
	{
		if (current->val > current->next->val)
			return (0);
		current = current->next;
	}
	return (1);
}
