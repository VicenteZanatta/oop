#include <iostream>
#include "util/linked_list.hpp"


List::List() : head(nullptr), tail(nullptr) {}

List::~List()
{
    Node* curr = head;
    while (curr != nullptr)
    {
        Node* aux = curr->next;
        delete curr->base;
        delete curr;
        curr = aux;
    }
    
}

void List::addNode(Commitment* com){
    
    Node* newNode = new Node(com);
    
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    
}

void List::printList() const
{
    Node* curr = head;

    while(curr != nullptr)
    {
        curr->base->printDefenition();
        curr = curr->next;
    }
}
