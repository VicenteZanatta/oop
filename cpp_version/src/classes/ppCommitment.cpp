#include <iostream>
#include "classes/commitment.hpp"
#include "classes/ppCommitment.hpp"

ppCommitment::ppCommitment(std::string arg_id, std::string arg_date, std::string arg_time, 
                        int arg_duration, int arg_priority, int arg_priorityFactor, 
                        bool arg_postponable)
            : Commitment(arg_id, arg_date, arg_time, arg_duration, arg_priority, 
                            arg_priorityFactor),
                isPostponable(arg_postponable){}

ppCommitment::~ppCommitment(){}
