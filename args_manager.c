/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:40:00 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/09 15:13:49 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"
//Check if the arg is a valid number
int	check_valid_nbr(const char *argv)
{
	int		i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i ++;
	if (argv[i] == '\0')
		return (1);
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]))
			return (1);
		i ++;
	}
	return (0);
}

//String to number (long int)
long int	ft_atol(const char *nptr)
{
	int			pos;
	int			sign;
	long int	nb;

	pos = 0;
	sign = 1;
	nb = 0;
	while ((nptr[pos] >= 9 && nptr[pos] <= 13) || nptr[pos] == 32)
		pos ++;
	if (nptr[pos] == '+')
		pos ++;
	else if (nptr[pos] == '-')
	{
		sign = -1;
		pos ++;
	}
	while (nptr[pos] >= '0' && nptr[pos] <= '9')
	{
		nb = nb * 10 + (nptr[pos] - '0');
		pos ++;
	}
	return (nb * sign);
}

//Check if the number is a valid int
int	is_duplicated(t_stack *stack, int nb)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == nb)
			return (1);
		current = current->next;
	}
	return (0);
}
