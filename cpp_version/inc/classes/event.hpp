#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <string>
#include "classes/commitment.hpp"

class Event : public Commitment
{
private:
    std::string eventName;
    std::string location;

public:
    Event(std::string arg_id, std::string arg_date, std::string arg_time, 
          int arg_duration, int arg_priority, std::string arg_eventName, 
          std::string arg_location);
    ~Event() override;

    std::string getEventName() const;
    std::string getLocation() const;
};

#endif