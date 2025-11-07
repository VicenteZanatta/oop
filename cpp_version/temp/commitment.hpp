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
    std::string definition;
    int duration;
    int priority;
    int priorityFactor;

public:
    Commitment(std::string id, std::string date, std::string time, int duration,
                int priority, int priorityFactor);
                
    virtual ~Commitment() = default;

    void increaseFactor(){priorityFactor++;};   // used to increase Priority factor by 1 if commitment isn't postponable 
    std::string limitString(const std::string& input, size_t maxLen);
    void printDefenition() const; 

    int getDayInt () const;
    int getMonthInt() const;
    int getYearInt() const;
    int getTimeInt() const;  // Will retunr (Hours*100+minutes) making easy to use for compare
    int getDuration() const { return duration; }
    int getPriority() const { return priority; }
    int getPriorityFactor() const { return priorityFactor; }    

    void setDefenition(std::string arg_definition);


};


#endif