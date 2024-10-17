/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:24:34 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 15:45:34 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Clear the values ra_movs, rb_movs, rr_movs, etc. of a node
void	clear_moves(t_node *node)
{
	node->ra_movs = 0;
	node->rb_movs = 0;
	node->rr_movs = 0;
	node->rra_movs = 0;
	node->rrb_movs = 0;
	node->rrr_movs = 0;
	node->total_moves = 0;
}

//Returns the min value of two given values
int	min_of_two(int val1, int val2)
{
	if (val1 < val2)
		return (val1);
	else if (val2 < val1)
		return (val2);
	else
		return (val1);
}
