#include <iostream>
#include "classes/ppCommitment.hpp"
#include "classes/orientation.hpp"

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
    Commitment::setDefenition("Orientação de " + studantName);
}

Orientation::~Orientation(){}

int Orientation::getDefenseDayInt()
{
    std::string dayString = thesisDefenseDate.substr(0, 2);
    return std::stoi(dayString);
}

int Orientation::getDefenseMonthInt()
{
    std::string monthString = thesisDefenseDate.substr(3, 2);
    return std::stoi(monthString);
}

int Orientation::getDefenseYearInt()
{
    std::string yearString = thesisDefenseDate.substr(6, 4);
    return std::stoi(yearString);
}

int Orientation::getDefenseTimeInt()
{
    std::string hourString = thesisDefenseTime.substr(0, 2);
    std::string minString = thesisDefenseTime.substr(3, 2);

    int hour = std::stoi(hourString);
    int min = std::stoi(minString);

    return hour * 100 + min; // Ex: input 10:50 -> output 1050
}