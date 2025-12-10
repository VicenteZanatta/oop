#include "util/commitment_list.hpp"
#include <iostream>
#include <fstream>

CommitmentList::CommitmentList() : head(nullptr), tail(nullptr) {}

CommitmentList::~CommitmentList() {
    clear();
}

void CommitmentList::addCommitment(Commitment* com) {
    Node* node = new Node{com, nullptr};

    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

bool CommitmentList::removeCommitment(const std::string& id) {
    if (!head) return false;

    Node* curr = head;
    Node* prev = nullptr;

    while (curr) {
        if (curr->data->getId() == id) {
            if (prev)
                prev->next = curr->next;
            else
                head = curr->next;

            if (curr == tail)
                tail = prev;

            delete curr->data;
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }

    return false;
}

Commitment* CommitmentList::find(const std::string& id) const {
    Node* curr = head;
    while (curr) {
        if (curr->data->getId() == id)
            return curr->data;
        curr = curr->next;
    }
    return nullptr;
}

bool CommitmentList::isEmpty() const {
    return head == nullptr;
}

void CommitmentList::clear() {
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr->data;
        delete curr;
        curr = next;
    }
    head = tail = nullptr;
}

void CommitmentList::printCommitmentList(CommitmentList* List, ListOf commStatus, std::ofstream *file) {
        
    Node* node = List->head;
        
    while (node->next != nullptr)
    {
        switch (commStatus){
            case All:
                node->data->printComplet(file);
                break;

            case Confirmed:
                node->data->printConfirmed(file);
                break;

            case Postponade:
                node->data->printPostponaded(file);
                *file << node->moreImportanteCommitment << std::endl;
                break;

            case Canceled:
                node->data->printCanceled(file);
                *file << node->moreImportanteCommitment << std::endl;
                break;

            default:
                break;
        }

        node = node->next;
    }     
        
}

void CommitmentList::printListOfCanceled(std::ofstream* file){
    printCommitmentList(this, Canceled, file);
}

void CommitmentList::printListOfConfirmed(std::ofstream* file){
    printCommitmentList(this, Confirmed, file);
}

void CommitmentList::printListOfPostponaded(std::ofstream* file){
    printCommitmentList(this, Postponade, file);
}

void CommitmentList::printListOfAll(std::ofstream* file){
    printCommitmentList(this, All, file);
}