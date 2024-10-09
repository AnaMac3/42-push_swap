/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:13:16 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/09 10:45:32 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Rules reverse rotate rra, rrb, rrr:
//Last element to first position

void	rra(t_stack *a)
{
	t_node	*last;
	t_node	*second_last;

	if (a->size < 2)
		return ;
	last = a->top;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = a->top;
	a->top = last;
}

void	rrb(t_stack *b)
{
	t_node	*last;
	t_node	*second_last;

	if (b->size < 2)
		return ;
	last = b->top;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = b->top;
	b->top = last;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
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
    //rra
    ft_printf("\n\nReverse rotate a (rra) (el último ahora es el primero)\n");
    rra(a);
    ft_printf("Stack a después de rra: \n");
    print_stack(a);
	//rrb
    ft_printf("\n\nReverse rotate b (rrb) (el último ahora es el primero)\n");
    rrb(b);
    ft_printf("Stack b después de rrb: \n");
    print_stack(b);
    //rrr
    ft_printf("\n\nReverse rotate a y b a la vez\n");
    rrr(a, b);
    ft_printf("Stack a después de rrr: \n");
    print_stack(a);
    ft_printf("Stack b después de rrr: \n");
    print_stack(b);

    free_stack(a);
    free_stack(b);
    return (0);
}*/