#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include "util/linked_list.hpp"

class MergeSort {
public:
    static void sortByDateTime(List* list);
    
private:
    static List::Node* mergeSort(List::Node* head, List::Node** newTail);
    static List::Node* split(List::Node* head);
    static List::Node* merge(List::Node* left, List::Node* right, List::Node** tail);
    static bool compareCommitments(Commitment* a, Commitment* b);
};

#endif