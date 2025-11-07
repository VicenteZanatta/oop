#include <iostream>
#include <algorithm>
#include "util/merge_sort.hpp"

void MergeSort::sort(List* list, SortCriteria criteria) {
    if (!list || !list->getHead() || !list->getHead()->next) {
        return; 
    }
    
    List::Node* newTail = nullptr;
    List::Node* newHead = mergeSort(list->getHead(), &newTail, criteria);
    
    list->setHead(newHead);
    list->setTail(newTail);
}

void MergeSort::sortByDateTime(List* list) {
    sort(list, BY_DATE_TIME);
}

void MergeSort::sortByPriorityDesc(List* list) {
    sort(list, BY_PRIORITY_DESC);
}

void MergeSort::sortByDurationAsc(List* list) {
    sort(list, BY_DURATION_ASC);
}

void MergeSort::sortByIdAsc(List* list) {
    sort(list, BY_ID_ASC);
}

List::Node* MergeSort::mergeSort(List::Node* head, List::Node** newTail, SortCriteria criteria) {
    if (!head || !head->next) {
        if (head && !head->next) {
            *newTail = head; 
        }
        return head;
    }
    
    List::Node* middle = split(head);
    
    List::Node* leftTail = nullptr;
    List::Node* rightTail = nullptr;
    
    List::Node* left = mergeSort(head, &leftTail, criteria);
    List::Node* right = mergeSort(middle, &rightTail, criteria);
    
    return merge(left, right, newTail, criteria);
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

List::Node* MergeSort::merge(List::Node* left, List::Node* right, List::Node** tail, SortCriteria criteria) {
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
    
    // Selecionar a função de comparação baseada no critério
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
    
    List::Node* result = nullptr;
    List::Node* current = nullptr;
    
    // Inicializar a lista mesclada
    if (compareFunction(left->base, right->base)) {
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
        if (compareFunction(left->base, right->base)) {
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
        while (current->next) {
            current = current->next;
        }
    } else if (right) {
        current->next = right;
        right->prev = current;
        while (current->next) {
            current = current->next;
        }
    }
    
    *tail = current;
    return result;
}

bool MergeSort::compareByDateTime(Commitment* a, Commitment* b) { 
    // Critério principal: data e hora crescente
    if (a->getYearInt() != b->getYearInt())
        return a->getYearInt() < b->getYearInt();
    
    if (a->getMonthInt() != b->getMonthInt())
        return a->getMonthInt() < b->getMonthInt();

    if (a->getDayInt() != b->getDayInt())
        return a->getDayInt() < b->getDayInt();

    if (a->getStartHour() != b->getStartHour())
        return a->getStartHour() < b->getStartHour();

    if (a->getStartMinute() != b->getStartMinute())
        return a->getStartMinute() < b->getStartMinute();
        
    // Empate em data/hora - aplicar tiebreaker
    return tiebreaker(a, b);
}

bool MergeSort::compareByPriorityDesc(Commitment* a, Commitment* b) {
    // Critério principal: prioridade decrescente usando getPriorityScore()
    int scoreA = a->getPriorityScore();
    int scoreB = b->getPriorityScore();
    
    if (scoreA != scoreB)
        return scoreA > scoreB; // Decrescente
    
    // Empate no score de prioridade - aplicar tiebreaker
    return tiebreaker(a, b);
}

bool MergeSort::compareByDurationAsc(Commitment* a, Commitment* b) {
    // Critério principal: duração crescente
    if (a->getDuration() != b->getDuration())
        return a->getDuration() < b->getDuration(); // Crescente
    
    // Empate na duração - aplicar tiebreaker
    return tiebreaker(a, b);
}

bool MergeSort::compareByIdAsc(Commitment* a, Commitment* b) {
    // Critério principal: ID crescente
    if (a->getId() != b->getId())
        return a->getId() < b->getId(); // Crescente
    
    // Empate no ID - aplicar tiebreaker
    return tiebreaker(a, b);
}

bool MergeSort::tiebreaker(Commitment* a, Commitment* b) {
    // 1º Critério de desempate: Compromisso que inicia primeiro (data/hora)
    if (a->getYearInt() != b->getYearInt())
        return a->getYearInt() < b->getYearInt();
    
    if (a->getMonthInt() != b->getMonthInt())
        return a->getMonthInt() < b->getMonthInt();

    if (a->getDayInt() != b->getDayInt())
        return a->getDayInt() < b->getDayInt();

    if (a->getStartHour() != b->getStartHour())
        return a->getStartHour() < b->getStartHour();

    if (a->getStartMinute() != b->getStartMinute())
        return a->getStartMinute() < b->getStartMinute();

    // 2º Critério de desempate: Usar priority score como critério secundário
    int scoreA = a->getPriorityScore();
    int scoreB = b->getPriorityScore();
    
    if (scoreA != scoreB)
        return scoreA > scoreB; // Maior priority score primeiro

    // 3º Critério de desempate: Ordem alfabética da descrição
    return a->getDescription() < b->getDescription();
}