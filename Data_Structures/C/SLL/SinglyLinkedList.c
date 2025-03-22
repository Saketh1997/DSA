#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct int_Node{
    int data;
    struct int_Node* next;
}int_Node;

int_Node* create_int_Node(int val){
    int_Node* node = malloc(sizeof(int_Node));
    node->data = val;
    node->next = NULL;
    return node;
}

void append_int_Node(int_Node* list, int val){
    int_Node* current = list;
    while(current->next != NULL){
        current = current->next;
    }
    int_Node* newNode = create_int_Node(val);
    current->next = newNode;
    newNode->next = NULL;
    return;
}

void delete_int_node(int_Node* list, int val){
    int_Node* current = list;
    int_Node* previous = NULL;
    while(current->data != val){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
    return;
}

void print_list(int_Node* list){
    int_Node* current = list;
    do{
        printf("The values in the list are: %d\n", current->data);
        current = current->next;
    }while(current->next != NULL);
    return;
}

void main(){
    printf("Welcome to my demo of Linked list\n");
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int_Node *my_list = create_int_Node(a);
    append_int_Node(my_list, b);
    append_int_Node(my_list, c);
    append_int_Node(my_list, d);
    append_int_Node(my_list, e);
    print_list(my_list);
    delete_int_node(my_list, 3);
    print_list(my_list);
}