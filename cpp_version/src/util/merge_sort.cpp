#include <iostream>
#include "util/merge_sort.hpp"


void MergeSort::sortByDateTime(List* list) {
    if (!list || !list->getHead() || !list->getHead()->next) {
        return; 
    }
    
    List::Node* newTail = nullptr;
    List::Node* newHead = mergeSort(list->getHead(), &newTail);
    
    list->setHead(newHead);
    list->setTail(newTail);
}

List::Node* MergeSort::mergeSort(List::Node* head, List::Node** newTail) {
    if (!head || !head->next) {
        if (head && !head->next) {
            *newTail = head; 
        }
        return head;
    }
    
    List::Node* middle = split(head);
    
    List::Node* leftTail = nullptr;
    List::Node* rightTail = nullptr;
    
    List::Node* left = mergeSort(head, &leftTail);
    List::Node* right = mergeSort(middle, &rightTail);
    
    return merge(left, right, newTail);
}

List::Node* MergeSort::split(List::Node* head) {
    if (!head || !head->next) return nullptr;
    
    List::Node* slow = head;
    List::Node* fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    List::Node* middle = slow->next;
    slow->next = nullptr;
    if (middle) {
        middle->prev = nullptr;
    }
    
    return middle;
}

List::Node* MergeSort::merge(List::Node* left, List::Node* right, List::Node** tail) {
    if (!left) {
        *tail = right;
        while ((*tail) && (*tail)->next) {
            *tail = (*tail)->next;
        }
        return right;
    }
    if (!right) {
        *tail = left;
        while ((*tail) && (*tail)->next) {
            *tail = (*tail)->next;
        }
        return left;
    }
    
    List::Node* result = nullptr;
    List::Node* current = nullptr;
    
    // Inicializar a lista mesclada
    if (compareCommitments(left->base, right->base)) {
        result = left;
        left = left->next;
    } else {
        result = right;
        right = right->next;
    }
    current = result;
    current->prev = nullptr;
    
    // Mesclar as duas listas
    while (left && right) {
        if (compareCommitments(left->base, right->base)) {
            current->next = left;
            left->prev = current;
            left = left->next;
        } else {
            current->next = right;
            right->prev = current;
            right = right->next;
        }
        current = current->next;
    }
    
    // Anexar os elementos restantes
    if (left) {
        current->next = left;
        left->prev = current;
        // Encontrar o último nó
        while (current->next) {
            current = current->next;
        }
    } else if (right) {
        current->next = right;
        right->prev = current;
        // Encontrar o último nó
        while (current->next) {
            current = current->next;
        }
    }
    
    *tail = current;
    return result;
}

bool MergeSort::compareCommitments(Commitment* a, Commitment* b) { 
    if (a->getYearInt() != b->getYearInt())
        return a->getYearInt() < b->getYearInt();
    
    if (a->getMonthInt() != b->getMonthInt())
        return a->getMonthInt() < b->getMonthInt();

    if (a->getDayInt() != b->getDayInt())
        return a->getDayInt() < b->getDayInt();

    if(a->getStartHour() != b->getStartHour())
        return a->getStartHour() < b->getStartHour();

    if(a->getStartMinute() != b->getStartMinute())
        return a->getStartMinute() < b->getStartMinute();
        
}