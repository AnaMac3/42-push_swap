/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:05:17 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/09 10:07:41 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Rules swap sa, sb y ss:

void	sa(t_stack *a)
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
}

void	sb(t_stack *b)
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
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

//PRUEBA
/*
int main()
{
    t_stack *a;
    t_stack *b;
    int i;
	int	j;

    a = init_stack();
    b = init_stack();
    i = 5;
    while (i > 0)
    {
        push(a, i);
        i --;
    }
	j = 10;
	while (j > 5)
    {
        push(b, j);
        j --;
    }
    
    ft_printf("Stack a inicial: \n");
    print_stack(a);
    ft_printf("Stack b inicial: \n");
    print_stack(b);
    //sa
    ft_printf("\n\nSwap a (sa) (cambiar los dos primeros nums de A)\n");
    sa(a);
    ft_printf("Stack a después de sa: \n");
    print_stack(a);
	//sb
    ft_printf("\n\nSwap b (sb) (cambiar los dos primeros nums de B)\n");
    sb(b);
    ft_printf("Stack b después de sb: \n");
    print_stack(b);
    //ss
    ft_printf("\n\nSwap a y swap b a la vez\n");
    ss(a, b);
    ft_printf("Stack a después de ss: \n");
    print_stack(a);
    ft_printf("Stack b después de ss: \n");
    print_stack(b);

    free_stack(a);
    free_stack(b);
    return (0);
}*/