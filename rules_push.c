/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:15:19 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/09 13:01:24 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Rules push pa, pb:
//top of b stack to top of a
void	pa(t_stack *a, t_stack *b)
{
	t_node	*first_b;

	if (b->size == 0)
		return ;
	first_b = b->top;
	b->top = b->top->next;
	first_b->next = a->top;
	a->top = first_b;
	a->size ++;
	b->size --;
}
//top of a stack to top of b
void	pb(t_stack *a, t_stack *b)
{
	t_node	*first_a;

	if (a->size == 0)
		return ;
	first_a = a->top;
	a->top = a->top->next;
	first_a->next = b->top;
	b->top = first_a;
	b->size ++;
	a->size --;
}

//PRUEBA
/*
int main()
{
    t_stack *a;
    t_stack *b;
    int i;

    a = init_stack();
    b = init_stack();
    i = 5;
    while (i > 0)
    {
        push(a, i);
        i --;
    }
    
    ft_printf("Stack a inicial: \n");
    print_stack(a);
    ft_printf("Stack b inicial: \n");
    print_stack(b);
    //pb
    ft_printf("\n\nPush b (pb) (mover de A a B)\n");
    pb(a, b);
    ft_printf("Stack a después de pb: \n");
    print_stack(a);
    ft_printf("Stack b después de pb: \n");
    print_stack(b);
    //pa
    ft_printf("\n\nPush a (pa) (mover de B a A)\n");
    pa(a, b);
    ft_printf("Stack a después de pa: \n");
    print_stack(a);
    ft_printf("Stack b después de pa: \n");
    print_stack(b);

    free_stack(a);
    free_stack(b);
    return (0);
}*/