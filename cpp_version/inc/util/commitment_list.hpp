#ifndef COMMITMENT_LIST_HPP
#define COMMITMENT_LIST_HPP

#include <string>
#include "util/linked_list_template.hpp"
#include "classes/commitment.hpp"

class CommitmentList {
private:
    LinkedListTemplate<Commitment> commitmentList;

public:
    using Node = typename LinkedListTemplate<Commitment>::Node;

    CommitmentList();
    ~CommitmentList();

    void addCommitment(Commitment* commitment);
    void removeCommitment(Commitment* commitment);
    void printCommitmentList(const std::string& filename) const;
    void printConfirmedList(const std::string& filename) const;
    bool isEmpty() const { return commitmentList.isEmpty(); }

    Node* getHead() const { return commitmentList.getHead(); }
    Node* getTail() const { return commitmentList.getTail(); }
    void setHead(Node* newHead) { commitmentList.setHead(newHead); }
    void setTail(Node* newTail) { commitmentList.setTail(newTail); }
    
    Node* getNext(Node* current) const { 
        return commitmentList.getNext(current);
    }
    
    Commitment* getData(Node* current) const { 
        return commitmentList.getData(current);
    }
    
    void clear();
    void clearWithoutData();
};

#endif