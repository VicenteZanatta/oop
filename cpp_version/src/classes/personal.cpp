#include <iostream>
#include "classes/personal.hpp"

// string lenght const have +1 size for \0 operand
int const DESCRIPTION_STRING_LENGTH = 51;
int const LOCATION_STRING_LENGTH    = 51;
int const MOTIVE_STRING_LENGTH      = 51;
int const PERSONAL_PRIORITY_FACTOR  = 2;


Personal::Personal(std::string arg_id, std::string arg_date, std::string arg_time, 
                  int arg_duration, int arg_priority,bool arg_postponable, 
                  std::string arg_description, std::string arg_location, 
                  std::string arg_motive)
                  
    : ppCommitment(arg_id, arg_date, arg_time, arg_duration, arg_priority, 
                  PERSONAL_PRIORITY_FACTOR, arg_postponable),
      description(arg_description), 
      location(arg_location),
      motive(arg_motive)
{
    Commitment::limitString(description, DESCRIPTION_STRING_LENGTH);
    Commitment::limitString(location, LOCATION_STRING_LENGTH);
    Commitment::limitString(motive, MOTIVE_STRING_LENGTH);
    Commitment::setDefenition(motive);
}

Personal::~Personal() {}

std::string Personal::getDescription() const {
    return description;
}

std::string Personal::getLocation() const {
    return location;
}