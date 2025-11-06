#include <iostream>
#include "classes/dept_meeting.hpp"

int const TOPIC_STRING_LENGTH = 51;
int const DEPARTMENT_MEETING_PRIORITY_FACTOR = 4;

DepartmentMeeting::DepartmentMeeting(std::string arg_id, std::string arg_date, 
                                     std::string arg_time, int arg_duration, 
                                     int arg_priority, bool arg_postponable, 
                                     std::string arg_topic)
    : ppCommitment(arg_id, arg_date, arg_time, arg_duration, arg_priority, 
                  DEPARTMENT_MEETING_PRIORITY_FACTOR, arg_postponable),
      topic(arg_topic)
{
    Commitment::limitString(topic, TOPIC_STRING_LENGTH);
    Commitment::setDefenition("Reunião de Departamento");
}

DepartmentMeeting::~DepartmentMeeting() = default;

std::string DepartmentMeeting::getTopic() const {
    return topic;
}