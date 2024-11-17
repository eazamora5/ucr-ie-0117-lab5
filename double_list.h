//Universidad de Costa Rica
//IE-0117 Programacion bajo plataformas abiertas
//Profesora: Carolina Trejos
//Estudiante: Enrique Zamora Solis
//Laboratorio 5 - Double-list.h

#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} DoubleList;

// Funciones para manejar la lista doblemente enlazada
DoubleList* create_list();
void insert_at_beginning(DoubleList* list, int data);
void insert_at_end(DoubleList* list, int data);
void insert_at_position(DoubleList* list, int data, int position);
void delete_by_data(DoubleList* list, int data);
Node* search_by_data(DoubleList* list, int data);
void print_forward(DoubleList* list);
void print_backward(DoubleList* list);
void free_list(DoubleList* list);

#endif
