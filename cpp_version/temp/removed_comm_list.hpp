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
        void printInfo() const;
    };
    
    LinkedListTemplate<RemovedComm> removedList;

public:
    RemovedCommitmentsList();
    ~RemovedCommitmentsList();

    void addRemovedCommitment(Commitment* commitment, const std::string& removerId);
    void printRemovedCommitments() const;
    bool isEmpty() const { return removedList.isEmpty(); }
    
    // Access methods for iteration
    auto getHead() const { return removedList.getHead(); }
    auto getTail() const { return removedList.getTail(); }
    
    // Clear the list (without deleting Commitment objects)
    void clear() { removedList.clear(); }
};

#endif