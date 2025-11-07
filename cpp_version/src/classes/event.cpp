#include <iostream>
#include "classes/event.hpp"

int const EVENT_NAME_STRING_LENGTH = 51;
int const LOCATION_STRING_LENGTH = 51;
int const EVENT_PRIORITY_FACTOR = 3;

Event::Event(std::string arg_id, std::string arg_date, std::string arg_time, 
             int arg_duration, int arg_priority, std::string arg_eventName, 
             std::string arg_location)
    : Commitment(arg_id, arg_date, arg_time, arg_duration, arg_priority, 
                 EVENT_PRIORITY_FACTOR, arg_eventName, false), // Eventos não são adiáveis por padrão
      eventName(arg_eventName), location(arg_location)
{
    Commitment::limitString(eventName, EVENT_NAME_STRING_LENGTH);
    Commitment::limitString(location, LOCATION_STRING_LENGTH);
    Commitment::setDefenition(eventName);
}

Event::~Event() = default;

std::string Event::getEventName() const {
    return eventName;
}

std::string Event::getLocation() const {
    return location;
}