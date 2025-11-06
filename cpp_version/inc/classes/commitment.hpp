#ifndef COMMITMENT_HPP
#define COMMITMENT_HPP

#include <iostream>
#include <string>

class Commitment
{
private:

    std::string id;
    std::string date;
    std::string time;
    int duration;
    int priority;
    int priorityFactor;

public:
    Commitment(std::string id, std::string date, std::string time, int duration,
                int priority, int priorityFactor);
    virtual ~Commitment() = default;

    
};


#endif