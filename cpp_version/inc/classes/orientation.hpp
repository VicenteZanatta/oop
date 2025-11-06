#ifndef ORIENTATION_HPP
#define ORIENTATION_HPP

#include <iostream>
#include "classes/ppCommitment.hpp"

class Orientation : public ppCommitment
{
private:
    std::string studantName;
    std::string level;
    std::string thesisDefenseDate;
    std::string thesisDefenseTime;
public:
    Orientation(std::string arg_id, std::string arg_date, std::string arg_time, 
                int arg_duration, int arg_priority, bool arg_postponable, 
                std::string arg_studentName, std::string level, 
                std::string thesisDefenseDate, std::string thesisDefenseTime);
    ~Orientation() override;

    int getDefenseDayInt();
    int getDefenseMonthInt();
    int getDefenseYearInt();
    int getDefenseTimeInt();  // Will retunr (Hours*100+minutes) making easy to use for compare

};


#endif