/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:40:00 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 16:31:12 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//If argc == 2 -> strchr spaces and split
char	**replace_and_split(const char *argv)
{
	char	*new_str;
	char	**new_argv;
	int		i;

	new_str = malloc(ft_strlen(argv) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (argv[i] != '\0')
	{
		if (ft_isspace(argv[i]))
			new_str[i] = ' ';
		else
			new_str[i] = argv[i];
		i ++;
	}
	new_str[i] = '\0';
	new_argv = ft_split(new_str, ' ');
	free(new_str);
	return (new_argv);
}

//Check if the arg is a valid number
static int	check_valid_nbr(const char *argv)
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

//Check if the number is a valid int
static int	is_duplicated(t_stack *stack, int nb)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->val == nb)
			return (1);
		current = current->next;
	}
	return (0);
}

//Manage and check args
int	check_mang_args(const char *argv, t_stack *stack)
{
	long int	nb;

	if (check_valid_nbr(argv) != 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	nb = ft_atol(argv);
	if (nb > 2147483647 || nb < -2147483648)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (is_duplicated(stack, nb) != 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	push_bottom(stack, nb);
	return (0);
}

int	full_stack_a(int argc, char **argv, t_stack *a)
{
	char	**new_argv;
	int		i;

	new_argv = NULL;
	if (argc == 2)
	{
		new_argv = replace_and_split(argv[1]);
		if (new_argv == NULL)
			return (1);
		argv = new_argv;
		i = 0;
	}
	else
		i = 1;
	while (argv[i] != NULL)
	{
		if (check_mang_args(argv[i], a) != 0)
			return (1);
		i ++;
	}
	if (new_argv)
		free_split_result(new_argv);
	return (0);
}
