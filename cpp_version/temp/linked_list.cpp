#include <iostream>
#include "util/linked_list.hpp"
#include "util/merge_sort.hpp"


List::List() : head(nullptr), tail(nullptr) {}

List::~List() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->base;
        delete current;
        current = next;
    }
}

void List::addNode(Commitment* commitment) {
    Node* newNode = new Node(commitment);
    
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void List::printList() const {
    Node* current = head;
    while (current) {
        current->base->printDefenition();
        current = current->next;
    }
}

void List::sortByDateTime() {
    MergeSort::sortByDateTime(this);
    
    if (head) {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        tail = current;
    } else {
        tail = nullptr;
    }
}

int List::getCount() const {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}