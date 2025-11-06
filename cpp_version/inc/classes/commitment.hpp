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

    void increaseFactor(){priorityFactor++;};   // used to increase Priority factor by 1 if commitment isn't postponable 
    std::string limitString(const std::string& input, size_t maxLen);    
    int getDayInt();
    int getMonthInt();
    int getYearInt();
    int getTimeInt();  // Will retunr (Hours*100+minutes) making easy to use for compare
};


#endif