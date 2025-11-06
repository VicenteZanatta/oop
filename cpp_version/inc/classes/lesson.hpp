#ifndef LESSON_HPP
#define LESSON_HPP

#include <iostream>
#include <string>
#include "classes/commitment.hpp"

class Lesson : public Commitment
{
private:

    std::string subject;
    std::string level;

public:

    Lesson(std::string id, std::string date, std::string time, int duration,
            int priority, std::string subject, std::string level);
    ~Lesson() override;
    
};


#endif