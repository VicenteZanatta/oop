#ifndef REMOVED_COMMITMENT_LIST_HPP
#define REMOVED_COMMITMENT_LIST_HPP

#include "util/linked_list.hpp"

class RemovedCommitmentList : public List
{
private:
    std::string moreImportantCommitment;

public:
    RemovedCommitmentList();
    
    void addRemovedCommitment(Commitment* commitment, const std::string& importantId);
    
    std::string getMoreImportantCommitment() const;
    void setMoreImportantCommitment(const std::string& importantId);
};

#endif