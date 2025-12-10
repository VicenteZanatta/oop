#include <iostream>
#include <string>
#include <fstream>
#include "classes/commitment.hpp"

int const ID_STRING_LENGHT       = 8;
int const DATE_STRING_LENGHT     = 11;
int const TIME_STRING_LENGHT     = 6;

Commitment::Commitment(std::string arg_id, std::string arg_date, std::string arg_time, 
                        int arg_duration, int arg_priority, int arg_priorityFactor,
                        std::string arg_description,
                        bool arg_isPostponable){
    
    id = limitString(arg_id, ID_STRING_LENGHT);
    date = limitString(arg_date, DATE_STRING_LENGHT);
    time = limitString(arg_time, TIME_STRING_LENGHT);
    duration = arg_duration;
    priority = arg_priority;
    priorityFactor = arg_priorityFactor;
    description = arg_description;
    isPostponable = arg_isPostponable;

    if(!isPostponable)
        increaseFactor();

    addFinishTime();
}

std::string Commitment::limitString(const std::string& input, size_t maxLen) 
{
    if (input.size() >= maxLen)
        return input.substr(0, maxLen);
    return input;
}

int Commitment::getDayInt() const
{
    std::string dayString = date.substr(0, 2);
    return std::stoi(dayString);
}

int Commitment::getMonthInt() const
{
    std::string monthString = date.substr(3, 2);
    return std::stoi(monthString);
}

int Commitment::getYearInt() const
{
    std::string yearString = date.substr(6, 4);
    return std::stoi(yearString);
}

void Commitment::printDefenition() const {std::cout << definition << std::endl;}    

void Commitment::setDefenition(std::string arg_definition) {definition = arg_definition;}

void Commitment::addFinishTime()
{
    int startHour = std::stoi(time.substr(0, 2));
    int startMinute = std::stoi(time.substr(3, 2));
    
    int totalStartMinutes = startHour * 60 + startMinute;
    
    int totalFinishMinutes = totalStartMinutes + duration;
    
    finishHour = totalFinishMinutes / 60;
    finishMin = totalFinishMinutes % 60;
    
    if (finishHour >= 24) {
        finishHour = 23;
        finishMin = 59;
    }
}

int Commitment::getStartHour() const
{
    return std::stoi(time.substr(0, 2));
}

int Commitment::getFinishHour() const
{
    return finishHour;
}

int Commitment::getStartMinute() const
{
    return std::stoi(time.substr(3, 2));
}

int Commitment::getFinishMinute() const
{
    return finishMin;
}

void Commitment::printConfirmed(std::ofstream* file)
{
    *file << date << time << std::endl;
    *file << id << std::endl;
    *file << description << std::endl;
    *file << std::endl;
}

void Commitment::printCanceled(std::ofstream* file)
{
    *file << id << std::endl;
    *file << description << std::endl;
    *file << priority << std::endl;
    *file << std::endl;
}

void Commitment::printPostponaded(std::ofstream* file)
{
    *file << id << std::endl;
    *file << description << std::endl;
    *file << priority << std::endl;
    *file << std::endl;
}

void Commitment::printComplet(std::ofstream* file)
{
    *file << id << " : " << description << std::endl;
    *file << "Início: " << date << time << std::endl;
    *file << "Fim: " << date << getFinishHour() << ":" << getFinishMinute() << std::endl;
    *file << "Prioridade: " << priority << std::endl;
    *file << std::endl; 
}