#ifndef MERGE_SORT_TEMPLATE_HPP
#define MERGE_SORT_TEMPLATE_HPP

template<typename ListType, typename DataType>
class MergeSortTemplate {
public:
    enum SortCriteria {
        DATE,
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
        
        bool (*compareFunction)(DataType*, DataType*) = getCompareFunction(criteria);
        
        Node* result = nullptr;
        Node* current = nullptr;
        
        if (compareFunction(list->getData(left), list->getData(right))) {
            result = left;
            left = list->getNext(left);
        } else {
            result = right;
            right = list->getNext(right);
        }
        current = result;
        current->setPrev(nullptr);

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
            current = list->getNext(current);
        }
        
        if (left) {
            current->setNext(left);
            left->setPrev(current);
            if (tail) {
                Node* temp = left;
                while (list->getNext(temp)) {
                    temp = list->getNext(temp);
                }
                *tail = temp;
            }
        } else {
            current->setNext(right);
            if (right) {
                right->setPrev(current);
            }
            if (tail) {
                Node* temp = right;
                while (temp && list->getNext(temp)) {
                    temp = list->getNext(temp);
                }
                *tail = temp;
            }
        }
        
        return result;
    }

    static bool (*getCompareFunction(SortCriteria criteria))(DataType*, DataType*) {
        switch (criteria) {
            case DATE: return compareByDateTime;
            case PRIORITY: return compareByPriorityDesc;
            case DURATION: return compareByDurationAsc;
            case ID: return compareByIdAsc;
            default: return compareByDateTime;
        }
    }

    static bool compareByDateTime(DataType* a, DataType* b) {
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

    static bool compareByPriorityDesc(DataType* a, DataType* b) {
        return a->getPriorityScore() > b->getPriorityScore();
    }

    static bool compareByDurationAsc(DataType* a, DataType* b) {
        return a->getDuration() < b->getDuration();
    }

    static bool compareByIdAsc(DataType* a, DataType* b) {
        return a->getId() < b->getId();
    }

public:
    static void sort(ListType* list, SortCriteria criteria = DATE) {
        if (!list || list->isEmpty()) {
            return; 
        }
        
        Node* newTail = nullptr;
        Node* newHead = mergeSort(list, list->getHead(), &newTail, criteria);
        
        list->setHead(newHead);
        list->setTail(newTail);
    }

    static void sortByDateTime(ListType* list) {
        sort(list, DATE);
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