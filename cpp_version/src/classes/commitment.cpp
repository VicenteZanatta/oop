#include <iostream>
#include <string>
#include "classes/commitment.hpp"

// string lenght const have +1 size for \0 operand

int const ID_STRING_LENGHT       = 8;  //"A000001[\0]"    
int const DATE_STRING_LENGHT     = 11;
int const TIME_STRING_LENGHT     = 6;


Commitment::Commitment(std::string arg_id, std::string arg_date, std::string arg_time, 
                        int arg_duration, int arg_priority, int arg_priorityFactor){
    
    id = limitString(arg_id, ID_STRING_LENGHT);
    date = limitString(arg_date, DATE_STRING_LENGHT);
    time = limitString(arg_time, TIME_STRING_LENGHT);
    duration = arg_duration;
    priority = arg_priority;
    priorityFactor = arg_priorityFactor;

}

std::string Commitment::limitString(const std::string& input, size_t maxLen) {
    if (input.size() >= maxLen)
        return input.substr(0, maxLen);
    return input;
}

int Commitment::getDayInt() const
{
    std::string dayString;
    dayString = date.substr(0,1);

    return std::stoi(dayString);
}

int Commitment::getMonthInt () const
{
    std::string monthString;
    monthString = date.substr(3,4);

    return std::stoi(monthString);
}

int Commitment::getYearInt () const
{
    std::string yearString;
    yearString = date.substr(6,9);

    return std::stoi(yearString);
}

int Commitment::getTimeInt () const
{
    std::string hourString;
    std::string minString;
    int hour;
    int min;

    hourString = time.substr(0,1);
    minString = time.substr(3,4);

    hour = std::stoi(hourString);
    min = std::stoi(minString);

    return   hour*100+min;      //Ex: input 10h50 -> output 1050
}

void Commitment::printDefenition() const {std::cout << definition << std::endl;}

void Commitment::setDefenition(std::string arg_definition){definition = arg_definition;}