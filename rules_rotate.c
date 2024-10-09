/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:01:54 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/09 10:08:03 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Rules rotate, ra, rb, rr:
//First element to last position
void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (a->size < 2)
		return ;
	first = a->top;
	last = a->top;
	while ((last->next) != NULL)
		last = last->next;
	a->top = first->next;
	last->next = first;
	first->next = NULL;
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*last;

	if (b->size < 2)
		return ;
	first = b->top;
	last = b->top;
	while ((last->next) != NULL)
		last = last->next;
	b->top = first->next;
	last->next = first;
	first->next = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
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
    //ra
    ft_printf("\n\nRotate a (ra) (el primer elemento ahora es el último)\n");
    ra(a);
    ft_printf("Stack a después de ra: \n");
    print_stack(a);
	//rb
    ft_printf("\n\nRotate b (rb) (el primer elemento ahora es el último)\n");
    rb(b);
    ft_printf("Stack b después de rb: \n");
    print_stack(b);
    //rr
    ft_printf("\n\nRotate a y rotate b a la vez\n");
    rr(a, b);
    ft_printf("Stack a después de rr: \n");
    print_stack(a);
    ft_printf("Stack b después de rr: \n");
    print_stack(b);

    free_stack(a);
    free_stack(b);
    return (0);
}*/