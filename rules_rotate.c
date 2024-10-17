/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:01:54 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 16:51:35 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Rules rotate, ra, rb, rr:
//mode == 0 --> final movement, print it and do it
//mode == 1 --> calling from doble rotate (rr or rrr), not print it
//First element to last position
void	ra(t_stack *a, int mode)
{
	t_node	*first;
	t_node	*last;

	if (a->size < 2)
		return ;
	first = a->top;
	last = a->top;
	while ((last->next) != NULL)
		last = last->next;
	a->top = first->next;
	last->next = first;
	first->next = NULL;
	if (mode == 0)
		ft_printf("ra\n");
}

void	rb(t_stack *b, int mode)
{
	t_node	*first;
	t_node	*last;

	if (b->size < 2)
		return ;
	first = b->top;
	last = b->top;
	while ((last->next) != NULL)
		last = last->next;
	b->top = first->next;
	last->next = first;
	first->next = NULL;
	if (mode == 0)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 1);
	rb(b, 1);
	ft_printf("rr\n");
}
