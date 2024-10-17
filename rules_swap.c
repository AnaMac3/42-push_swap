/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:05:17 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 16:52:41 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Rules swap sa, sb y ss:
//mode == 0 --> final movement, print it and do it
//mode == 1 --> calling from doble rotate (ss), not print it
//swap first two elements of a
void	sa(t_stack *a, int mode)
{
	t_node	*first;
	t_node	*second;

	if (a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	if (mode == 0)
		ft_printf("sa\n");
}

//swap first two elements of b
void	sb(t_stack *b, int mode)
{
	t_node	*first;
	t_node	*second;

	if (b->size < 2)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
	if (mode == 0)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 1);
	sb(b, 1);
	ft_printf("ss\n");
}
