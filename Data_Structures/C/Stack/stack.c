#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node{
    int data;
    node* newHead;
}node;

node* create(int val){
    node* node = malloc(sizeof(node));
    node->data = val;
    node->newHead = NULL;
    return node;
}

node* push(int val, node* stack){
    node* newNode = create(val);
    newNode->newHead = stack;
    return newNode;
}

// node* pop(node* stack){

// }