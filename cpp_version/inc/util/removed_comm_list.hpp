#ifndef REMOVED_COMMITMENTS_LIST_HPP
#define REMOVED_COMMITMENTS_LIST_HPP

#include <string>
#include <iostream>
#include "util/linked_list_template.hpp"
#include "classes/commitment.hpp"

class RemovedCommitmentsList {
private:
    struct RemovedComm {
        Commitment* removedCommitment;
        std::string moreImportantId;
        
        RemovedComm(Commitment* commitment, const std::string& removerId);
    };
    
    LinkedListTemplate<RemovedComm> removedList;

public:
    using Node = typename LinkedListTemplate<RemovedComm>::Node;

    RemovedCommitmentsList();
    ~RemovedCommitmentsList();

    void addRemovedCommitment(Commitment* commitment, const std::string& removerId);
    void printRemovedCommitments(const std::string& filename) const;
    bool isEmpty() const { return removedList.isEmpty(); }
    
    Node* getHead() const { return removedList.getHead(); }
    Node* getTail() const { return removedList.getTail(); }
    void setHead(Node* newHead) { removedList.setHead(newHead); }
    void setTail(Node* newTail) { removedList.setTail(newTail); }
    
    Node* getNext(Node* current) const { 
        return removedList.getNext(current);
    }
    
    RemovedComm* getData(Node* current) const { 
        return removedList.getData(current);
    }
    
    void clear() { removedList.clear(); }
};

#endif