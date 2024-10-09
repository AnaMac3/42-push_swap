/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacarul <amacarul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:23:52 by amacarul          #+#    #+#             */
/*   Updated: 2024/10/09 13:00:34 by amacarul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Funciones para manejar los stacks:
Inicializar el stack con el elemento top en NULL y size en 0.
Crear un nodo pasándole un valor entero.
Push: añadir un nodo a la parte de arriba del stack, pasando como argumentos
el stack y el valor de entero que tiene el nodo. La size del stack aumenta 1.
Imprimir el stack (esta va a sobrar después, en la función final no
vamos a querer imprimir el stack en ningún momento).
Liberar el stack: liberar cada uno de los nodos y el stack.

Ahora necesito otro conj de funciones para tratar la lista de argumentos que
me van a pasar. El primer elemento de la lista es el que está arriba del stack.
Creo que la lista de enteros me la van a pasar por stdin, separados por espacios (??)
Función que cuente cuántos argumentos me han pasado, y que me los
empiece a meter en el stack de atrás hacia adelante. Solo me tiene que
aceptar números enteros.
--> atoi para sacar los valores de la cadena con espacios??*/
#include "libpush_swap.h"

//Initialize stack
t_stack *init_stack(void)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}
//Create a node
t_node  *create_node(int value)
{
    t_node  *node = malloc(sizeof(t_node));
    node->value = value;
    node->next = NULL;
    return (node);
}
//Add a node at the top of the stack
void    push(t_stack *stack, int value)
{
    t_node  *new_node;

    new_node = create_node(value);
    if (stack->top == NULL)
        stack->top = new_node;
    else
    {
        new_node->next = stack->top;
        stack->top = new_node;
    }
    stack->size ++;
}
//Print the stack
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
//Free the stack
void    free_stack(t_stack *stack)
{
    t_node  *current;
    t_node  *next;
    
    current = stack->top;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}
