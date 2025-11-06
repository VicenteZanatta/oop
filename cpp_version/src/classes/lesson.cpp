#include <iostream>
#include <string>
#include "classes/lesson.hpp"

const int LESSON_PIORITY_FACTOR = 2 ;

Lesson::Lesson(std::string arg_id, std::string arg_date, std::string arg_time, int arg_duration,
            int arg_priority, std::string arg_subject, 
            std::string arg_level)

    : Commitment(arg_id, arg_date, arg_time, arg_duration, arg_priority,
                 LESSON_PIORITY_FACTOR),

        subject(arg_subject),
        level(arg_level){}

Lesson::~Lesson(){}