#include <iostream>
#include <string>
#include "classes/commitment.hpp"

// string lenght const have +1 size for \0 operand

int const ID_STRING_LENGHT       = 8;  //"A000001[\0]"    
int const DATE_STRING_LENGHT     = 11;
int const TIME_STRING_LENGHT     = 6;
int const NAME_STRING_LENGHT     = 51;


Commitment::Commitment(std::string arg_id, std::string arg_date, std::string arg_time, 
                        int arg_duration, int arg_priority, int arg_priorityFactor){
    
    id = arg_id;
    date = arg_date;
    time = arg_time;
    duration = arg_duration;
    priority = arg_priority;
    priorityFactor = arg_priorityFactor;

}

std::string Commitment::limitString(const std::string& input, size_t maxLen) {
    if (input.size() <= maxLen)
        return input;
    else
        return input.substr(0, maxLen); // string is truncated at max lenght
}
