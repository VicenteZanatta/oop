#ifndef COMMITMENT_LIST_HPP
#define COMMITMENT_LIST_HPP

#include "util/linked_list_template.hpp"
#include "classes/commitment.hpp"

class CommitmentList {
private:
    LinkedListTemplate<Commitment> commitmentList;

public:
    // Declarar tipos friend para permitir acesso
    friend class MergeSortTemplate<CommitmentList>;
    
    // Usar um tipo público para Node
    using Node = void*;

    CommitmentList();
    ~CommitmentList();

    void addCommitment(Commitment* commitment);
    void removeCommitment(Commitment* commitment);
    void printList() const;
    Commitment* findCommitmentById(const std::string& id) const;
    bool isEmpty() const { return commitmentList.isEmpty(); }

    // Métodos de acesso com casting
    Node getHead() const { return commitmentList.getHead(); }
    Node getTail() const { return commitmentList.getTail(); }
    void setHead(Node newHead) { commitmentList.setHead(static_cast<typename LinkedListTemplate<Commitment>::Node*>(newHead)); }
    void setTail(Node newTail) { commitmentList.setTail(static_cast<typename LinkedListTemplate<Commitment>::Node*>(newTail)); }
    
    // Métodos auxiliares para o merge sort
    Node getNext(Node current) const { 
        return commitmentList.getNext(static_cast<typename LinkedListTemplate<Commitment>::Node*>(current));
    }
    
    Commitment* getData(Node current) const { 
        return commitmentList.getData(static_cast<typename LinkedListTemplate<Commitment>::Node*>(current));
    }
    
    void clear();
    void clearWithoutData();
};

#endif