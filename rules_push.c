/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:15:19 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/18 12:52:41 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Rules push pa, pb:
//top of b stack to top of a
//mode == 0 --> final movement, print it and do it
//mode == 1 --> checker, not print it
void	pa(t_stack *a, t_stack *b, int mode)
{
	t_node	*first_b;

	if (b->size == 0)
		return ;
	first_b = b->top;
	b->top = b->top->next;
	first_b->next = a->top;
	a->top = first_b;
	a->size ++;
	b->size --;
	if (mode == 0)
		ft_printf("pa\n");
}

//top of a stack to top of b
void	pb(t_stack *a, t_stack *b, int mode)
{
	t_node	*first_a;

	if (a->size == 0)
		return ;
	first_a = a->top;
	a->top = a->top->next;
	first_a->next = b->top;
	b->top = first_a;
	b->size ++;
	a->size --;
	if (mode == 0)
		ft_printf("pb\n");
}
