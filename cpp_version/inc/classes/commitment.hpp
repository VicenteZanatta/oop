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
    std::string description;
    int duration;
    int priority;
    int priorityFactor;
    int finishHour;
    int finishMin;
    bool isPostponable;

    void addFinishTime();

public:
    Commitment(std::string id, std::string date, std::string time, int duration,
                int priority, int priorityFactor, std::string description, 
                bool isPostponable = false);
                
    virtual ~Commitment() = default;

    void increaseFactor(){priorityFactor++;};
    std::string limitString(const std::string& input, size_t maxLen);
    void printDefenition() const;

    int getDayInt () const;
    int getMonthInt() const;
    int getYearInt() const;
    int getStartHour() const;
    int getFinishHour() const;
    int getStartMinute() const;
    int getFinishMinute() const;
    int getDuration() const { return duration; }
    int getPriority() const { return priority; }
    int getPriorityFactor() const { return priorityFactor; }
    int getPriorityScore() const { return priority * priorityFactor; }
    bool getIsPostponable() const { return isPostponable; }
    std::string getDescription() const { return description; }
    std::string getId() const { return id; }

    void setDefenition(std::string arg_definition);

    void printConfirmed(std::ofstream* file);
    void printCanceled(std::ofstream* file);
    void printComplet(std::ofstream* file);
    void printPostponaded(std::ofstream* file);

};

#endif