/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:13:16 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 16:50:45 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Rules reverse rotate rra, rrb, rrr:
//mode == 0 --> final movement, print it and do it
//mode == 1 --> calling from doble rotate (rr or rrr), not print it
//Last element to first position
void	rra(t_stack *a, int mode)
{
	t_node	*last;
	t_node	*second_last;

	if (a->size < 2)
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
	if (mode == 0)
		ft_printf("rra\n");
}

void	rrb(t_stack *b, int mode)
{
	t_node	*last;
	t_node	*second_last;

	if (b->size < 2)
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
	if (mode == 0)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 1);
	rrb(b, 1);
	ft_printf("rrr\n");
}
