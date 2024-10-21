/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:39:21 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/21 12:35:15 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libchecker.h"

//Manage error
void	manage_error(t_stack *a, t_stack *b, char *line)
{
	free(line);
	free_stacks(a, b);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

//Read the line and execute the commands
void	try_moves(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0 && line)
		sa(a, 1);
	else if (ft_strcmp(line, "sb\n") == 0 && line)
		sb(b, 1);
	else if (ft_strcmp(line, "ss\n") == 0 && line)
		ss(a, b, 1);
	else if (ft_strcmp(line, "pa\n") == 0 && line)
		pa(a, b, 1);
	else if (ft_strcmp(line, "pb\n") == 0 && line)
		pb(a, b, 1);
	else if (ft_strcmp(line, "ra\n") == 0 && line)
		ra(a, 1);
	else if (ft_strcmp(line, "rb\n") == 0 && line)
		rb(b, 1);
	else if (ft_strcmp(line, "rr\n") == 0 && line)
		rr(a, b, 1);
	else if (ft_strcmp(line, "rra\n") == 0 && line)
		rra(a, 1);
	else if (ft_strcmp(line, "rrb\n") == 0 && line)
		rrb(b, 1);
	else if (ft_strcmp(line, "rrr\n") == 0 && line)
		rrr(a, b, 1);
	else
		manage_error(a, b, line);
}

void	read_commands(t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		try_moves(a, b, line);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

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
	read_commands(a, b);
	if (check_order(a) == 1 && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(a, b);
}
