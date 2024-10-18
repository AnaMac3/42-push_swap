# **Push_swap**
Proyecto push_swap del cursus 42.

### Recursos
Explicaciones del algoritmo turco &rarr; https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

Hoja de corrección &rarr; https://github.com/rizky/42-corrections/blob/master/push_swap.pdf

Visualizer &rarr; https://github.com/o-reo/push_swap_visualizer

### Flujo

```mermaid
graph LR;
    A["***main.c***"] --> B["Comprueba la cantidad de argumentos"];
    A --> C["Inicializa las stacks (***init_stack*** -> stack_manager.c) y las libera si son NULL (***free_stacks*** -> stack_manager.c)"];
    A --> D["***full_stack_a*** -> args_manager.c: Introduce los números pasados como argumentos en la stack A"];
    D --> E["***replace_and_split***: Si hay un único argumento, reemplaza los diferentes tipos de espacio por espacios normales y hace split (parte el string en diferentes strings tomando el espacio como separador)"];
    D --> F["***check_man_args***: comprueba la validez de los argumentos y los introduce en la stack A"];
    F --> G["***check_valid_nbr***: comprueba que los argumentos introducidos sean números"];
    F --> H["***ft_atol*** (./my_libft): convierte char* a long int. Después, en check_man_args se comprueba que el valor del número no supere los límites de int"];
    F --> I["***is_duplicated***: comprueba sihay algún elemento en la stack con el mismo valor del que vamos a introducir"];
    F --> J["***push_bottom*** (stack_manager.c): crea un nodo nuevo con el valor pasado como argumento y lo introduce al final de la stack (para mantener el orden relativo y que el primer argumento pasado esté en el top de la stack)"];
    D --> K["***free_split_result*** (other_utils.c): si se ha hecho split, se liberan sus resultados"];
    A --> L["***check_order*** (check_order.c): comprueba si los valores de la stack están ordenados de menor a mayor."];
    A --> M["***sort_stack***: ordena el stack según su número de elementos"];
    M --> N["***sort_2nb*** (sort_small_stack.c): ordena stacks de 2 elementos"];
    M --> O["***sort_3nb*** (sort_small_stack.c): ordena stacks de 3 elementos"];
    M --> P["***sort_4nb*** (sort_small_stack.c): ordena stacks de 4 elementos"];
    M --> Q["***sort_5nb*** (sort_small_stack.c): ordena stacks de 5 elementos"];
    M --> R["***sort_long_stack*** (sort_long_stack.c): ordena stacks de más de 5 elementos"];
    N --> S["Reglas: ***pa***, ***pb***, ***sa***, ***sb***, ***ss***, ***ra***, ***rb***, ***rr***, ***rra***, ***rrb***, ***rrr***, (rules_push.c, rules_swap.c, rules_rotate.c, rules_rev_rotate.c)"];
    O --> S;
    P --> S;
    Q --> S;
    R --> S;
    R --> T["Primero pasa dos elementos a la stack B. Después, cacula qué elemento de la stack A necesita menos movimientos para colocarse en su posición correcta en B y mueve ese elemento. Hace esto en bucle hasta que la stack A queda vacía. Por último, se asegura de que B quede ordenada de mayor a menor, y vuelca todos los elementos de B a A, donde quedarán ordenados de menor a mayor"];
    T --> U["Se asignan índices a los nodos de ambas stacks en cada vuelta con ***assign_index***"];
    T --> V["***calculate_total_moves*** (calculate_moves.c): calcula el total de movimientos (en A y en B) que necesita cada nodo de A para colocarse en su posición correcta en B"];
    V --> W["***clear_moves***: limpiar los datos en cada vuelta"];
    V --> X["***calculate_moves_in_a***: hace ra o rra dependiendo de su índice"];
    V --> Y["***calculate_pos_in_b***: calcula la posición en la que tiene que ir el nodo de A en la stack B"];
    V --> Z["***calculate_moves_in_b***: hace rb o rrb dependiendo de su índice"];
    V -->AA["***res_moves_a_b***": resume los movimientos: ra y rb son rr; rra y rrb son rrr];
    T --> AB["***find_best_node_to_move***: cuando ya sabemos el total de movimientos que necesita cada nodo para moverse, seleccionamos aquel que necesite menos movimientos"];
    T --> AC["***do_calculated_moves***: se ejecutan los movimientos guardados en el nodo más económico."];
    T --> AD["***max_value_to_top***: si el stack B no está en orden de mayor a menor, se rota hasta poner el valor máximo arriba"];
