#include <iostream>
#include <string>
#include "classes/lesson.hpp"

// string lenght const have +1 size for \0 operand
int const SUBJECT_STRING_LENGHT = 51;

const int LESSON_PIORITY_FACTOR = 2 ;

Lesson::Lesson(std::string arg_id, std::string arg_date, std::string arg_time, int arg_duration,
            int arg_priority, std::string arg_subject, 
            std::string arg_level)

    : Commitment(arg_id, arg_date, arg_time, arg_duration, arg_priority,
                 LESSON_PIORITY_FACTOR),

        subject(arg_subject),
        level(arg_level)                //doesn't need string limitation because only can assume 3 values handle during reading 
{
        Commitment::limitString(subject, SUBJECT_STRING_LENGHT);
}

Lesson::~Lesson(){}