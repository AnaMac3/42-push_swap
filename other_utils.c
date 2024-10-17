/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:16:47 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/17 16:21:00 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

void	free_split_result(char **split_result)
{
	char	**current;

	current = split_result;
	while (*current)
	{
		free(*current);
		current ++;
	}
	free(split_result);
}
