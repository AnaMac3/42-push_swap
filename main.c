/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:47:45 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 16:42:22 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2nb(a);
	if (a->size == 3)
		sort_3nb(a);
	if (a->size == 4)
		sort_4nb(a, b);
	if (a->size == 5)
		sort_5nb(a, b);
	if (a->size > 5)
		sort_long_stack(a, b);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (1);
	a = init_stack();
	b = init_stack();
	if (a == NULL || b == NULL)
	{
		free_stacks(a, b);
		return (1);
	}
	if (full_stack_a(argc, argv, a) != 0)
	{
		free_stacks(a, b);
		return (1);
	}
	if (check_order(a) == 1)
	{
		free_stacks(a, b);
		return (0);
	}
	sort_stack(a, b);
	free_stacks(a, b);
	return (0);
}
