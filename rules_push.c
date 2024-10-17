/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:15:19 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 16:49:42 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Rules push pa, pb:
//top of b stack to top of a
void	pa(t_stack *a, t_stack *b)
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
	ft_printf("pa\n");
}

//top of a stack to top of b
void	pb(t_stack *a, t_stack *b)
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
	ft_printf("pb\n");
}
