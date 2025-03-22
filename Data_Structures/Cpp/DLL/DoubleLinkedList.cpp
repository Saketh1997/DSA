#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* create_node(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append_node(node* oldList, int val){
    node* newNode = (node*)malloc(sizeof(node));
    node* current = oldList;
    newNode->data = val;
    while (current->next != NULL){
        current = current->next;;
    }
    current->next = newNode;
    newNode->prev = current;
    return;
}

void delete_node(node* list, int val){
    node* current = list;
    node* previous = NULL;
    while(current->data != val){
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    current->next->prev = previous;
    free(current);
    return;
}

void print_list(node* list){
    node* current = list;
    do{
        printf("The values in the list are: %d\n", current->data);
        current = current->next;
    }while(current->next != NULL);
    return;
}

int main(){
    printf("Welcome to my demo of Linked list\n");
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    node *my_list = create_node(a);
    append_node(my_list, b);
    append_node(my_list, c);
    append_node(my_list, d);
    append_node(my_list, e);
    print_list(my_list);
    delete_node(my_list, 3);
    print_list(my_list);
    return 0;
}