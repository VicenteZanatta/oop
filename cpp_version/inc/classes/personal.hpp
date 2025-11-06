#ifndef PERSONAL_HPP
#define PERSONAL_HPP

#include <iostream>
#include <string>
#include "classes/ppCommitment.hpp"

class Personal : public ppCommitment
{
private:
    std::string description;
    std::string location;
    std::string motive;

public:
    Personal(std::string arg_id, std::string arg_date, std::string arg_time, 
             int arg_duration, int arg_priority, bool arg_postponable, 
             std::string arg_description, std::string arg_location, std::string arg_motive);

    ~Personal() override;

    std::string getDescription() const;
    std::string getLocation() const;
};

#endif