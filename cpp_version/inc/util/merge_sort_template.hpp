#ifndef MERGE_SORT_TEMPLATE_HPP
#define MERGE_SORT_TEMPLATE_HPP

#include "util/commitment_list.hpp"

template<typename ListType>
class MergeSortTemplate {
public:
    enum SortCriteria {
        DATE_TIME,
        PRIORITY, 
        DURATION,
        ID
    };

private:
    using Node = typename ListType::Node;

    static Node* mergeSort(ListType* list, Node* head, Node** newTail, SortCriteria criteria) {
        if (!head || !list->getNext(head)) {
            if (head && newTail) {
                *newTail = head;
            }
            return head;
        }
        
        Node* middle = getMiddle(list, head);
        Node* nextOfMiddle = list->getNext(middle);
        
        // Split the list
        middle->setNext(nullptr);
        if (nextOfMiddle) {
            nextOfMiddle->setPrev(nullptr);
        }
        
        Node* leftTail = nullptr;
        Node* rightTail = nullptr;
        
        Node* left = mergeSort(list, head, &leftTail, criteria);
        Node* right = mergeSort(list, nextOfMiddle, &rightTail, criteria);
        
        return merge(list, left, right, newTail, criteria);
    }

    static Node* getMiddle(ListType* list, Node* head) {
        if (!head) return nullptr;
        
        Node* slow = head;
        Node* fast = list->getNext(head);
        
        while (fast && list->getNext(fast)) {
            slow = list->getNext(slow);
            fast = list->getNext(list->getNext(fast));
        }
        
        return slow;
    }

    static Node* merge(ListType* list, Node* left, Node* right, Node** tail, SortCriteria criteria) {
        if (!left) {
            if (tail) *tail = right;
            return right;
        }
        if (!right) {
            if (tail) *tail = left;
            return left;
        }
        
        bool (*compareFunction)(Commitment*, Commitment*) = getCompareFunction(criteria);
        
        Node* result = nullptr;
        
        // Choose the head of merged list
        if (compareFunction(list->getData(left), list->getData(right))) {
            result = left;
            left = list->getNext(left);
        } else {
            result = right;
            right = list->getNext(right);
        }
        
        Node* current = result;
        current->setPrev(nullptr);
        
        // Merge the lists
        while (left && right) {
            if (compareFunction(list->getData(left), list->getData(right))) {
                current->setNext(left);
                left->setPrev(current);
                left = list->getNext(left);
            } else {
                current->setNext(right);
                right->setPrev(current);
                right = list->getNext(right);
            }
            current = current->getNext();
        }
        
        // Attach remaining nodes
        if (left) {
            current->setNext(left);
            left->setPrev(current);
            if (tail) {
                // Find the actual tail
                Node* temp = left;
                while (temp->getNext()) {
                    temp = temp->getNext();
                }
                *tail = temp;
            }
        } else {
            current->setNext(right);
            if (right) {
                right->setPrev(current);
            }
            if (tail) {
                // Find the actual tail
                Node* temp = right;
                while (temp && temp->getNext()) {
                    temp = temp->getNext();
                }
                *tail = temp;
            }
        }
        
        return result;
    }

    static bool (*getCompareFunction(SortCriteria criteria))(Commitment*, Commitment*) {
        switch (criteria) {
            case DATE_TIME: return compareByDateTime;
            case PRIORITY: return compareByPriorityDesc;
            case DURATION: return compareByDurationAsc;
            case ID: return compareByIdAsc;
            default: return compareByDateTime;
        }
    }

    static bool compareByDateTime(Commitment* a, Commitment* b) {
        if (a->getYearInt() != b->getYearInt())
            return a->getYearInt() < b->getYearInt();
        if (a->getMonthInt() != b->getMonthInt())
            return a->getMonthInt() < b->getMonthInt();
        if (a->getDayInt() != b->getDayInt())
            return a->getDayInt() < b->getDayInt();
        if (a->getStartHour() != b->getStartHour())
            return a->getStartHour() < b->getStartHour();
        return a->getStartMinute() < b->getStartMinute();
    }

    static bool compareByPriorityDesc(Commitment* a, Commitment* b) {
        return a->getPriorityScore() > b->getPriorityScore();
    }

    static bool compareByDurationAsc(Commitment* a, Commitment* b) {
        return a->getDuration() < b->getDuration();
    }

    static bool compareByIdAsc(Commitment* a, Commitment* b) {
        return a->getId() < b->getId();
    }

public:
    static void sort(ListType* list, SortCriteria criteria = DATE_TIME) {
        if (!list || list->isEmpty()) {
            return; 
        }
        
        Node* newTail = nullptr;
        Node* newHead = mergeSort(list, list->getHead(), &newTail, criteria);
        
        list->setHead(newHead);
        list->setTail(newTail);
        
        // Ensure the head's prev is null
        if (newHead) {
            newHead->setPrev(nullptr);
        }
    }

    static void sortByDateTime(ListType* list) {
        sort(list, DATE_TIME);
    }

    static void sortByPriority(ListType* list) {
        sort(list, PRIORITY);
    }

    static void sortByDuration(ListType* list) {
        sort(list, DURATION);
    }

    static void sortById(ListType* list) {
        sort(list, ID);
    }
};

#endif