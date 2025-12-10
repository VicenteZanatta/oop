#ifndef COMMITMENT_LIST_HPP
#define COMMITMENT_LIST_HPP

#include <string>
#include "classes/commitment.hpp"
#include <fstream>

class CommitmentList
{
private:
    struct Node
    {
        Commitment* data;
        std::string moreImportanteCommitment; 
        Node* next;
    };
    
    Node* head;
    Node* tail;


public:
    enum ListOf{
        Confirmed,
        Canceled,
        Postponade,
        All
    };

    CommitmentList();
    ~CommitmentList();


    void addCommitment(Commitment* com);
    bool removeCommitment(const std::string& id);

    void printCommitmentList(CommitmentList* List, ListOf commStatus = All, std::ofstream *file);
    void printListOfCanceled(std::ofstream* file);
    void printListOfConfirmed(std::ofstream* file);
    void printListOfPostponaded(std::ofstream* file);
    void printListOfAll(std::ofstream* file);

    Commitment* find(const std::string& id) const;
    bool isEmpty() const;
    void clear();
    };

#endif


