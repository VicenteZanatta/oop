#include <iostream>
#include <string>
#include "classes/commitment.hpp"

Commitment::Commitment(std::string arg_id, std::string arg_date, std::string arg_time, 
                        int arg_duration, int arg_priority, int arg_priorityFactor){
    
    id = arg_id;
    date = arg_date;
    time = arg_time;
    duration = arg_duration;
    priority = arg_priority;
    priorityFactor = arg_priorityFactor;

}
