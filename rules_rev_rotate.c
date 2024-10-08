/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:13:16 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/08 17:17:10 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Rules reverse rotate rra, rrb, rrr:
//Last element to first position

void	rra(t_stack *a)
{
	t_node	*last;
	t_node	*second_last;

	if(a->size < 2)
		return ;
	last = a->top;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = a->top;
	a->top = last;
}

void	rrb(t_stack *b)
{
	t_node	*last;
	t_node	*second_last;

	if(b->size < 2)
		return ;
	last = b->top;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = b->top;
	b->top = last;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}