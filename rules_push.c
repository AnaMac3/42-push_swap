/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:15:19 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/08 17:16:40 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

//Rules push pa, pb:

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

void    pb(t_stack *a, t_stack *b)
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

t_stack *create_stack()
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

t_node  *create_node(int value)
{
    t_node  *node = malloc(sizeof(t_node));
    node->value = value;
    node->next = NULL;
    return (node);
}

void    print_stack(t_stack *stack)
{
    t_node  *current;

    current = stack->top;
    ft_printf("Stack (size = %d): \n", stack->size);
    while (current != NULL)
    {
        ft_printf("%d ", current->value);
        current = current->next;
    }
    ft_printf("\n");
}

int main()
{
    t_stack *a;
    t_stack *b;
    int i;
    t_node  *new;

    a = create_stack();
    b = create_stack();
    i = 5;
    while (i > 0)
    {
        new = create_node(i);
        new->next = a->top;
        a->top = new;
        a->size ++;
    }
    
    ft_printf("Stack a inicial: \n");
    print_stack(a);
    ft_printf("Stack b inicial: \n");
    print_stack(b);
    
    ft_printf("\n\nPush a (pa) (mover de B a A)\n");
    pa(a,b);
    ft_printf("Stack a después de pa: \n");
    print_stack(a);
    ft_printf("Stack b después de pb: \n");
    print_stack(b);
    
    free(a);
    free(b);
    return (0);
}