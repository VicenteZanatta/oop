#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node Node;

typedef struct list List;

List* initList();

Node* initNode();

Node* createNode(void* data);

void addNode(void* data, List* list);

void printList(List* list);

#endif