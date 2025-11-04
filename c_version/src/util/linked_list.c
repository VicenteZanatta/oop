#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/commitment.h"
#include "../inc/lesson.h"

typedef struct node{

    struct node* prev;
    void* data;
    struct node* next;

}Node;

typedef struct list{

    struct node* head;
    struct node* tail;

}List;


List* initList(){

    List* list = malloc(sizeof(list));

    list->head = NULL;
    list->tail = NULL;

    return list;

}

Node* initNode(){

    Node* node = malloc(sizeof(node));

    if(node == NULL){
        printf("ERROR WHILE NODE MALLOC");
        return NULL;
    }

    node->prev = NULL;
    node->data = NULL;
    node->next = NULL;

    return node;
}

Node* createNode(void* data){

    Node* node = initNode();

    node->data = data;

    return node; 

}


void addNode(void* data, List* list){

    Node* node = createNode(data);
    
    if(list->head == NULL){     // list->head is NULL if list is empty, in this case, the added node is head and tail
        list->head = node;
        list->tail = node;
    }else{                      //add new node to the and of the list and make it the new tail
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }       

}

void printList(List* list){

    Node* node = list->head;
    
    while(node != NULL){
        node = node->next;
    }
        

    printf("\nEND OF LINKED LIST\n");
}