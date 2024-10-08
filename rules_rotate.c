/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:01:54 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/08 17:16:47 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Rules rotate, ra, rb, rr:
//First element to last position
void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if(a->size < 2)
		return ;
	first = a->top;
	last = a->top;
	while ((last->next) != NULL)
		last = last->next;
	a->top = first->next;
	last->next = first;
	first->next = NULL;
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*last;

	if(b->size < 2)
		return ;
	first = b->top;
	last = b->top;
	while ((last->next) != NULL)
		last = last->next;
	b->top = first->next;
	last->next = first;
	first->next = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}