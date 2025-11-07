#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "classes/commitment.hpp"

class MergeSort;

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
    void printList() const;
    void sortByDateTime(); 

    Node* getHead() const { return head; }
    Node* getTail() const { return tail; }
    int getCount() const;
    
    void setHead(Node* newHead) { head = newHead; }
    void setTail(Node* newTail) { tail = newTail; }
    
private:
    friend class MergeSort;
};

#endif