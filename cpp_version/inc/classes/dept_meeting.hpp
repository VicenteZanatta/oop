#ifndef DEPARTMENT_MEETING_HPP
#define DEPARTMENT_MEETING_HPP

#include <iostream>
#include <string>
#include "classes/commitment.hpp"

class DepartmentMeeting : public Commitment
{
private:
    std::string topic;

public:
    DepartmentMeeting(std::string arg_id, std::string arg_date, std::string arg_time, 
                     int arg_duration, int arg_priority, bool arg_postponable, 
                     std::string arg_topic);
    ~DepartmentMeeting() override;

    std::string getTopic() const;
};

#endif