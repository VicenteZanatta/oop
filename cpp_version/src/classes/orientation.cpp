#include <iostream>
#include "classes/ppCommitment.hpp"
#include "classes/orientation.hpp"

// string lenght const have +1 size for \0 operand
int const NAME_STRING_LENGHT = 51;

int const ORIENTATION_PRIORITY_FACTOR = 1;

Orientation::Orientation(std::string arg_id, std::string arg_date, std::string arg_time, 
                        int arg_duration, int arg_priority, bool arg_postponable, 
                        std::string arg_studentName, std::string arg_level,
                        std::string arg_DefenseDate, std::string arg_DefenseTime)
            
            : ppCommitment(arg_id, arg_date, arg_time, arg_duration, arg_priority, 
                            ORIENTATION_PRIORITY_FACTOR, arg_postponable),
                studantName(arg_studentName),
                level(arg_level),
                thesisDefenseDate(arg_DefenseDate),
                thesisDefenseTime(arg_DefenseTime)
{
    Commitment::limitString(studantName, NAME_STRING_LENGHT);
}


Orientation::~Orientation(){}


int Orientation::getDefenseDayInt()
{
    std::string dayString;
    dayString = thesisDefenseDate.substr(0,1);

    return std::stoi(dayString);
}

int Orientation::getDefenseMonthInt()
{
    std::string monthString;
    monthString = thesisDefenseDate.substr(3,4);

    return std::stoi(monthString);
}

int Orientation::getDefenseYearInt()
{
    std::string yearString;
    yearString = thesisDefenseDate.substr(6,9);

    return std::stoi(yearString);
}

int Orientation::getDefenseTimeInt()
{
    std::string hourString;
    std::string minString;
    int hour;
    int min;

    hourString = thesisDefenseTime.substr(0,1);
    minString = thesisDefenseTime.substr(3,4);

    hour = std::stoi(hourString);
    min = std::stoi(minString);

    return   hour*100+min;      //Ex: input 10h50 -> output 1050
}