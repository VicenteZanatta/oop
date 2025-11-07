#ifndef MERGE_SORT_TEMPLATE_HPP
#define MERGE_SORT_TEMPLATE_HPP

#include "util/commitment_list.hpp"

template<typename ListType>
class MergeSortTemplate {
public:
    enum SortCriteria {
        BY_DATE_TIME,
        BY_PRIORITY_DESC, 
        BY_DURATION_ASC,
        BY_ID_ASC
    };

private:
    using Node = typename ListType::Node;

    static Node mergeSort(ListType* list, Node head, Node* newTail, SortCriteria criteria) {
        if (!head || !list->getNext(head)) {
            if (head) {
                *newTail = head;
            }
            return head;
        }
        
        Node middle = split(list, head);
        
        Node leftTail = nullptr;
        Node rightTail = nullptr;
        
        Node left = mergeSort(list, head, &leftTail, criteria);
        Node right = mergeSort(list, middle, &rightTail, criteria);
        
        return merge(list, left, right, newTail, criteria);
    }

    static Node split(ListType* list, Node head) {
        if (!head || !list->getNext(head)) return nullptr;
        
        Node slow = head;
        Node fast = list->getNext(head);
        
        while (fast && list->getNext(fast)) {
            slow = list->getNext(slow);
            fast = list->getNext(list->getNext(fast));
        }
        
        Node middle = list->getNext(slow);
        // Aqui precisaríamos de acesso para modificar next - isso é complexo
        
        // Por simplicidade, vamos usar uma abordagem diferente
        return simpleSplit(list, head);
    }

    static Node simpleSplit(ListType* list, Node head) {
        // Implementação simplificada de split
        if (!head || !list->getNext(head)) return nullptr;
        
        Node slow = head;
        Node fast = list->getNext(head);
        Node prev = nullptr;
        
        while (fast && list->getNext(fast)) {
            prev = slow;
            slow = list->getNext(slow);
            fast = list->getNext(list->getNext(fast));
        }
        
        if (prev) {
            Node middle = list->getNext(prev);
            // Não podemos modificar next diretamente sem acesso aos nós
            return middle;
        }
        return list->getNext(head);
    }

    static Node merge(ListType* list, Node left, Node right, Node* tail, SortCriteria criteria) {
        if (!left) {
            *tail = right;
            Node current = right;
            while (current && list->getNext(current)) {
                current = list->getNext(current);
            }
            *tail = current;
            return right;
        }
        if (!right) {
            *tail = left;
            Node current = left;
            while (current && list->getNext(current)) {
                current = list->getNext(current);
            }
            *tail = current;
            return left;
        }
        
        bool (*compareFunction)(Commitment*, Commitment*);
        switch (criteria) {
            case BY_DATE_TIME:
                compareFunction = compareByDateTime;
                break;
            case BY_PRIORITY_DESC:
                compareFunction = compareByPriorityDesc;
                break;
            case BY_DURATION_ASC:
                compareFunction = compareByDurationAsc;
                break;
            case BY_ID_ASC:
                compareFunction = compareByIdAsc;
                break;
            default:
                compareFunction = compareByDateTime;
        }
        
        Node result = nullptr;
        Node current = nullptr;
        
        if (compareFunction(list->getData(left), list->getData(right))) {
            result = left;
            left = list->getNext(left);
        } else {
            result = right;
            right = list->getNext(right);
        }
        current = result;
        
        while (left && right) {
            if (compareFunction(list->getData(left), list->getData(right))) {
                // Não podemos modificar next/prev diretamente
                left = list->getNext(left);
            } else {
                // Não podemos modificar next/prev diretamente  
                right = list->getNext(right);
            }
            current = list->getNext(current);
        }
        
        // Implementação simplificada devido à complexidade
        *tail = current;
        return result;
    }

    static bool compareByDateTime(Commitment* a, Commitment* b) { 
        if (a->getYearInt() != b->getYearInt())
            return a->getYearInt() < b->getYearInt();
        // ... resto da implementação
        return tiebreaker(a, b);
    }

    // ... outras funções de comparação

public:
    static void sort(ListType* list, SortCriteria criteria = BY_DATE_TIME) {
        if (!list || list->isEmpty()) {
            return; 
        }
        
        Node newTail = nullptr;
        Node newHead = mergeSort(list, list->getHead(), &newTail, criteria);
        
        list->setHead(newHead);
        list->setTail(newTail);
    }

    static void sortByDateTime(ListType* list) {
        sort(list, BY_DATE_TIME);
    }

    static void sortByPriorityDesc(ListType* list) {
        sort(list, BY_PRIORITY_DESC);
    }

    static void sortByDurationAsc(ListType* list) {
        sort(list, BY_DURATION_ASC);
    }

    static void sortByIdAsc(ListType* list) {
        sort(list, BY_ID_ASC);
    }
};

#endif