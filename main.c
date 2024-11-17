//Universidad de Costa Rica
//IE-0117 Programacion bajo plataformas abiertas
//Profesora: Carolina Trejos
//Estudiante: Enrique Zamora Solis
//Laboratorio 5 - main.c

#include <stdio.h>
#include "double_list.h"

int main() {
    DoubleList* list = create_list();

    printf("Laboratorio #5\n");
    printf("Funciones en listas doblemente enlazadas\n");
    // Insertar nodos en varias posiciones
    printf("Insertando 10 en el inicio de la lista:\n");
    insert_at_beginning(list, 10);
    print_forward(list);
    printf("Insertando 95 en el inicio de la lista:\n");
    insert_at_beginning(list, 95);
    print_forward(list);
    printf("Insertando 20 al final de la lista:\n");
    insert_at_end(list, 20);
    print_forward(list);
    printf("Insertando 30 al final de la lista:\n");
    insert_at_end(list, 30);
    print_forward(list);
    printf("Insertando 15 en la posicion 3 de la lista:\n");
    insert_at_position(list, 15, 3);
    print_forward(list);
    printf("Insertando 9 en la posicion 4 de la lista:\n");
    insert_at_position(list, 9, 4);
    print_forward(list);


    // Eliminar nodo por data
    delete_by_data(list, 20);
    printf("Lista hacia adelante después de eliminar 20:\n");
    print_forward(list);

    // Buscar un nodo específico
    Node* found = search_by_data(list, 15);
    if (found != NULL) {
        printf("Nodo con data 15 encontrado.\n");
    } else {
        printf("Nodo con data 15 no encontrado.\n");
    }

    printf("Lista hacia atrás:\n");
    print_backward(list);

    printf("Lista hacia adelante:\n");
    print_forward(list);

    // Liberar memoria
    free_list(list);

    return 0;
}
