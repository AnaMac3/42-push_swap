/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:47:45 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/09 15:14:21 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			i;
	long int	nb;

	if (argc < 2)
		return (1);
	a = init_stack();
	b = init_stack();
	i = argc - 1;
	while (i >= 1)
	{
		if (check_valid_nbr(argv[i]) != 0)
		{
			ft_printf("Error\n");
			return (1);
		}
		nb = ft_atol(argv[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			ft_printf("Error\n");
			return (1);
		}
		if (is_duplicated(a, nb) != 0)
		{
			ft_printf("Error\n");
			return (1);
		}
		push(a, nb);
		i --;
	}
	ft_printf("Stack a inicial: \n");
	print_stack(a);
	//Prueba con pb
	ft_printf("\nPush b (pb) (mover de A a B)\n");
	pb(a, b);
	ft_printf("Stack a después de pb: \n");
	print_stack(a);
	ft_printf("Stack b después de pb: \n");
	print_stack(b);
	free_stack(a);
	free_stack(b);
	return (0);
}