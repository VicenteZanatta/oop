#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "classes/commitment.hpp"

class List
{
private:

    struct Node{
 
        Node* prev;
        Commitment* base;
        Node* next;
        Node(Commitment* com) : prev(nullptr), base(com), next(nullptr){}       
    };

    Node* head;
    Node* tail;

public:

    List();
    ~List();

    void addNode(Commitment* Commitment);
};




#endif