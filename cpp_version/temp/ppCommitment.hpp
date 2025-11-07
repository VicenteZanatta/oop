#ifndef PPCOMMITMENT_H
#define PPCOMMITMENT_H

#include <iostream>
#include <string>
#include "classes/commitment.hpp"

class ppCommitment : public Commitment
{
private:

    bool isPostponable;

public:
    ppCommitment(std::string arg_id, std::string arg_date, std::string arg_time, 
                        int arg_duration, int arg_priority, int arg_priorityFactor, 
                        bool arg_postponable);
    ~ppCommitment() override;

    bool getIsPostponable() const { return isPostponable; }
};



#endif