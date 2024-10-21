# **Push_swap**
Proyecto push_swap del cursus 42.

El proyecto consiste en crear un programa que ordene de manera ascendente una lista de números enteros pasada como argumento. Se trabaja con dos stacks, el A y el B; el A es la que se recibe y la que tiene que devolverse ordenado, el B funciona como auxiliar.

Las operaciones que se pueden utilizar son las siguientes:

- sa (swap a): intercambia los dos primeros elementos del stack A.
- sb (swap b): intercambia los dos primeros elementos del stack B.
- ss (swap a y swap b a la vez)
- pa (push a): toma el primer elemento del stack A y lo pone el primero en el stack B.
- pb (push b): toma el primer elemento del stack B y lo pone el primero en el stack A.
- ra (rotate a): Desplaza hacia arriba todos los elementos del stack A una posición; el primer elemento se convierte en el último.
- rb (rotate b): Desplaza hacia arriba todos los elementos del stack B una posición; el primer elemento se convierte en el último.
- rr (ra y rb a la vez)
- rra (reverse rotate a): Desplaza hacia abajo todos los elementos del stack A una posicion; el último elemento se convierte en el primero.
- rrb (reverse rotate b): Desplaza hacia abajo todos los elementos del stack B una posicion; el último elemento se convierte en el primero.
- rrr (rra y rrb a la vez)


### Flujo de push_swap

```mermaid
graph LR;
    A["***main.c***"] --> B["Primero comprueba la cantidad de argumentos."];
    A --> C["Inicializa las stacks con ***init_stack*** (stack_manager.c) y las libera si son NULL con ***free_stacks*** (stack_manager.c)."];
    A --> D["***full_stack_a*** (args_manager.c): introduce los números pasados como argumentos en la stack A."];
    D --> E["***replace_and_split*** (args_manager.c): si hay un único argumento, reemplaza los diferentes tipos de espacio por espacios normales con ***ft_isspace*** (my_libft/ft_isspace.c)y hace split con ***ft_split***(my_libft/ft_slit.c)."];
    D --> F["***check_man_args*** (args_manager.c): comprueba la validez de los argumentos y los introduce en la stack A."];
    F --> G["***check_valid_nbr*** (args_manager.c): comprueba que los argumentos introducidos sean números."];
    F --> H["***ft_atol*** (my_libft/ft_atol.c): convierte char* a long int. Después, en check_man_args se comprueba que el valor del número no supere los límites de int."];
    F --> I["***is_duplicated*** (args_manager.c): comprueba que el elemento a introducir en la stack no esté duplicado."];
    F --> J["***push_bottom*** (stack_manager.c): crea un nodo nuevo con el valor pasado como argumento y lo introduce al final de la stack (para mantener el orden relativo y que el primer argumento pasado esté en el top de la stack)."];
    D --> K["***free_split_result*** (other_utils.c): si se ha hecho split, se liberan sus resultados."];
    A --> L["***check_order*** (check_order.c): comprueba si los valores de la stack están ordenados de menor a mayor."];
    A --> M["***sort_stack*** (main.c): ordena el stack según su número de elementos."];
    M --> N["***sort_2nb*** (sort_small_stack.c): ordena stacks de 2 elementos."];
    M --> O["***sort_3nb*** (sort_small_stack.c): ordena stacks de 3 elementos."];
    M --> P["***sort_4nb*** (sort_small_stack.c): ordena stacks de 4 elementos."];
    M --> Q["***sort_5nb*** (sort_small_stack.c): ordena stacks de 5 elementos."];
    M --> R["***sort_long_stack*** (sort_long_stack.c): ordena stacks de más de 5 elementos."];
    N --> S["Reglas: ***pa***, ***pb***, ***sa***, ***sb***, ***ss***, ***ra***, ***rb***, ***rr***, ***rra***, ***rrb***, ***rrr*** (rules_push.c, rules_swap.c, rules_rotate.c, rules_rev_rotate.c)."];
    O --> S;
    P --> S;
    Q --> S;
    R --> S;
    R --> T["Primero pasa dos elementos a la stack B. Después, cacula qué elemento de la stack A necesita menos movimientos para colocarse en su posición correcta en B y mueve ese elemento. Hace esto en bucle hasta que la stack A queda vacía. Por último, se asegura de que B quede ordenada de mayor a menor, y vuelca todos los elementos de B a A, donde quedarán ordenados de menor a mayor."];
    T --> U["Se asignan índices a los nodos de ambas stacks en cada vuelta con ***assign_index***(sort_long_stack.c)."];
    T --> V["***calculate_total_moves*** (calculate_moves.c): calcula el total de movimientos en las stacks A y B que necesita cada nodo de A para colocarse en su posición correcta en B."];
    V --> W["***clear_moves*** (calculate_moves_utils.c): limpia los datos en cada vuelta."];
    V --> X["***calculate_moves_in_a*** (calculate_moves.c): calcula la cantidad de ra o rra que necesita cada nodo de A para colocarse en el top del stack."];
    V --> Y["***calculate_pos_in_b*** (calculate_moves.c): calcula la posición en B en la que tiene que ir el nodo de A."]
    V --> Z["***calculate_moves_in_b*** (calculate_moves.c): calcula la cantidad de rb o rrb que necesita el nodo de B para colocarse en el top del stack."];
    V -->AA["***res_moves_a_b*** (calculate_moves.c): resume los movimientos de ra y rb en rr; y rra y rrb en rrr."];
    T --> AB["***find_best_node_to_move*** (sort_long_stack.c): selecciona el nodo de A que menos movimientos necesita para colocarse en su posición correcta en B."];
    T --> AC["***do_calculated_moves*** (sort_long_stack.c): ejecuta los movimientos guardados en el nodo más económico."];
    T --> AD["***max_value_to_top*** (sort_long_stack.c): si el stack B no está en orden de mayor a menor, se rota hasta poner el valor máximo arriba"];
```

### Recursos
Explicaciones del algoritmo turco &rarr; [AQUÍ](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) y [AQUÍ](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

Hoja de corrección &rarr; [AQUÍ](https://github.com/rizky/42-corrections/blob/master/push_swap.pdf)

Visualizer &rarr; [AQUÍ](https://github.com/o-reo/push_swap_visualizer)
