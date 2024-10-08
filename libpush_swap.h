/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:15:51 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/08 17:16:56 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_SWAP_H
# define LIBPUSH_SWAP_H
#include "my_libft/libft.h"
#include <stdlib.h>

//# include ..

//definir estructura de stacks
/*
typedef struct s_stack
{
	struct s_node //def del nodo dentro de la estructura del stack, anidado
	{
		int				value; //valor del nodo
		struct s_node	*next; //puntero al siguiente nodo
	} *top; //puntero al nodo superior de la pila
	int	size; //tamaño de la pila
}	t_stack;
*/
//Otra manera de hacerlo...
//Creo que esta segunda es mejor porque si no igual no puedo cambiar los nodos de sitio



//STRUCT
typedef struct s_node
{
	int	value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int	size;
}	t_stack;

//RULES
//rules_swap.c
void	sa (t_stack *a);
void	sb (t_stack *b);
void	ss(t_stack *a, t_stack *b);

//rules_push.c
void	pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);

//rules_rotate.c
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

//rules_rev_rotate.c
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);




#endif