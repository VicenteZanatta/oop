#include <iostream>
#include "classes/ppCommitment.hpp"
#include "classes/orientation.hpp"

// string lenght const have +1 size for \0 operand
int const NAME_STRING_LENGHT = 51;

int const ORIENTATION_PRIORITY_FACTOR = 1;

Orientation::Orientation(std::string arg_id, std::string arg_date, std::string arg_time, 
                        int arg_duration, int arg_priority, bool arg_postponable, 
                        std::string arg_studentName, std::string arg_level)
            
            : ppCommitment(arg_id, arg_date, arg_time, arg_duration, arg_priority, 
                            ORIENTATION_PRIORITY_FACTOR, arg_postponable),
                studantName(arg_studentName),
                level(arg_level)
{
    Commitment::limitString(studantName, NAME_STRING_LENGHT);
}


Orientation::~Orientation(){}
