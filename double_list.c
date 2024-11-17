//Universidad de Costa Rica
//IE-0117 Programacion bajo plataformas abiertas
//Profesora: Carolina Trejos
//Estudiante: Enrique Zamora Solis
//Laboratorio 5

#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

// Crear una nueva lista vacía
DoubleList* create_list() {
    DoubleList* list = (DoubleList*)malloc(sizeof(DoubleList));
    list->head = list->tail = NULL;
    return list;
}

// Insertar nodo al inicio
void insert_at_beginning(DoubleList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = list->head;

    if (list->head != NULL) {
        list->head->prev = new_node;
    }
    list->head = new_node;

    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

// Insertar nodo al final
void insert_at_end(DoubleList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = new_node;
    }
    list->tail = new_node;

    if (list->head == NULL) {
        list->head = new_node;
    }
}

// Insertar nodo en una posición específica
void insert_at_position(DoubleList* list, int data, int position) {
    if (position <= 0) {
        insert_at_beginning(list, data);
        return;
    }

    Node* current = list->head;
    int index = 0;

    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == NULL) {
        insert_at_end(list, data);
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = current->next;
    new_node->prev = current;

    if (current->next != NULL) {
        current->next->prev = new_node;
    } else {
        list->tail = new_node;
    }
    current->next = new_node;
}

// Eliminar el primer nodo que contiene el dato especificado
void delete_by_data(DoubleList* list, int data) {
    Node* current = list->head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) return;

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }

    free(current);
}

// Buscar un nodo por su valor de data
Node* search_by_data(DoubleList* list, int data) {
    Node* current = list->head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Recorrer la lista hacia adelante
void print_forward(DoubleList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Recorrer la lista hacia atrás
void print_backward(DoubleList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Liberar toda la lista
void free_list(DoubleList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}
