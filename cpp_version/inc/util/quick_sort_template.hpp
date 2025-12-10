#ifndef QUICK_SORT_TEMPLATE_HPP
#define QUICK_SORT_TEMPLATE_HPP

template<typename ListType, typename DataType>
class QuickSortTemplate {
public:
    enum SortCriteria {
        DATE,
        PRIORITY, 
        DURATION,
        ID
    };

    using Node = typename ListType::Node;

private:
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

    static bool (*getCompareFunction(SortCriteria c))(DataType*, DataType*) {
        switch (c) {
            case DATE: return compareByDateTime;
            case PRIORITY: return compareByPriorityDesc;
            case DURATION: return compareByDurationAsc;
            case ID: return compareByIdAsc;
            default: return compareByDateTime;
        }
    }

    static Node* partition(Node* head, Node* end,
                           Node** newHead, Node** newEnd,
                           bool (*compare)(DataType*, DataType*)) {

        Node* pivot = end;
        Node* prev = nullptr;
        Node* curr = head;
        Node* tail = pivot;

        // nova cabeça e cauda serão atualizadas
        *newHead = nullptr;
        *newEnd = tail;

        while (curr != pivot) {
            if (compare(curr->getData(), pivot->getData())) {
                // Nó vai para a lista de esquerda
                if (!(*newHead)) 
                    *newHead = curr;

                prev = curr;
                curr = curr->next;
            } else {
                // Nó maior ou igual vai para a direita (atrás do pivot)
                if (prev) 
                    prev->next = curr->next;

                Node* tmp = curr->next;
                curr->next = nullptr;
                tail->next = curr;
                tail = curr;

                curr = tmp;
            }
        }

        if (!(*newHead))
            *newHead = pivot;

        *newEnd = tail;

        return pivot;
    }

    static Node* quickSortRecur(Node* head, Node* end,
                                bool (*compare)(DataType*, DataType*)) {

        if (!head || head == end)
            return head;

        Node* newHead = nullptr;
        Node* newEnd = nullptr;

        Node* pivot = partition(head, end, &newHead, &newEnd, compare);

        // Se pivot não é a cabeça, ordenar a lista da esquerda
        if (newHead != pivot) {
            Node* tmp = newHead;
            while (tmp->next != pivot)
                tmp = tmp->next;
            tmp->next = nullptr;

            newHead = quickSortRecur(newHead, tmp, compare);

            // Reanexar pivot
            tmp = getTail(newHead);
            tmp->next = pivot;
        }

        // Ordenar a lista da direita
        pivot->next = quickSortRecur(pivot->next, newEnd, compare);

        return newHead;
    }

    // obtém último node (tail)
    static Node* getTail(Node* curr) {
        while (curr && curr->next)
            curr = curr->next;
        return curr;
    }

public:

    static void sort(ListType* list, SortCriteria criteria = DATE) {

        if (!list || list->isEmpty()) return;

        Node* head = list->getHead();
        Node* tail = getTail(head);

        auto cmp = getCompareFunction(criteria);

        Node* newHead = quickSortRecur(head, tail, cmp);
        Node* newTail = getTail(newHead);

        list->setHead(newHead);
        list->setTail(newTail);
    }

    static void sortByDateTime(ListType* list) { sort(list, DATE); }
    static void sortByPriority(ListType* list) { sort(list, PRIORITY); }
    static void sortByDuration(ListType* list) { sort(list, DURATION); }
    static void sortById(ListType* list) { sort(list, ID); }
};

#endif
