#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "classes/lesson.hpp"
#include "classes/commitment.hpp"
#include "classes/orientation.hpp"
#include "classes/event.hpp"
#include "classes/dept_meeting.hpp"
#include "classes/personal.hpp"
#include "util/commitment_list.hpp"
#include "util/file_input.hpp"

bool stringToBool(std::string& );
std::string validateLevel(const std::string&);
Lesson* readLesson(std::ifstream& File, std::string arg_id);
Orientation* readOrientation(std::ifstream& File, std::string arg_id);
Event* readEvent(std::ifstream& File, std::string arg_id);
DepartmentMeeting* readDepartmentMeeting(std::ifstream& File, std::string arg_id);
Personal* readPersonal(std::ifstream& File, std::string arg_id);

int readInputFile(std::string fileName, CommitmentList* commitmentList){

    std::ifstream File(fileName);   // used to read file
    std::string textLine;           // used to hold text line read 

    if (!File.is_open()){
        std::cout << "ERROR WHIL TRYING TO OPEN FILE" << std::endl;
        return 1;
    }             
        
    
    while(getline(File, textLine))
    {
        if(!textLine.empty())
            processCommitment(File, textLine, commitmentList);
    }
    
    File.close();
    return 0;
}

void processCommitment(std::ifstream& File, std::string& textLine, CommitmentList* commitmentList)
{
    char commitmentType = textLine[0];

    switch(commitmentType){ 
        case 'A':
            commitmentList->addCommitment(readLesson(File, textLine)); // CORREÇÃO: addCommitment
            break;
        case 'O':
            commitmentList->addCommitment(readOrientation(File, textLine)); // CORREÇÃO: addCommitment
            break;
        case 'E':
            commitmentList->addCommitment(readEvent(File, textLine)); // CORREÇÃO: addCommitment
            break;
        case 'R':
            commitmentList->addCommitment(readDepartmentMeeting(File, textLine)); // CORREÇÃO: addCommitment
            break;
        case 'P':
            commitmentList->addCommitment(readPersonal(File, textLine)); // CORREÇÃO: addCommitment
            break;
        default:    
            std::cout << "TYPE [" << commitmentType << "] NOT KNOWN" << std::endl;
            exit(EXIT_FAILURE); 
            break;    
    }
}

Lesson* readLesson(std::ifstream& File, std::string arg_id)
{
    std::string id;
    std::string dateTimeLine;
    std::string date;
    std::string time;
    std::string durationString;
    std::string priorityString;
    std::string subject;
    std::string level;
    int duration;
    int priority; 
    
    std::getline(File, dateTimeLine);
    std::getline(File, durationString);
    std::getline(File, subject);
    std::getline(File, level);
    std::getline(File, priorityString);

    id = arg_id;
    std::istringstream issDateTime(dateTimeLine);
    issDateTime >> date >> time;
    duration = std::stoi(durationString);
    priority = std::stoi(priorityString);
    level = validateLevel(level);
    
    return new Lesson(id, date, time, duration, priority, subject, level);
}

Orientation* readOrientation(std::ifstream& File, std::string arg_id)
{
    std::string id;
    std::string dateTimeLine;
    std::string date;
    std::string time;
    std::string durationString;
    std::string priorityString;
    std::string postponableString;
    std::string studentName;
    std::string level;
    std::string defenseString;
    std::string defenseDate;
    std::string defenseTime;
    bool isPostponable;
    int duration;
    int priority; 
    
    std::getline(File, dateTimeLine);
    std::getline(File, durationString);
    std::getline(File, postponableString);
    std::getline(File, studentName);
    std::getline(File, level);
    std::getline(File, defenseString);
    std::getline(File, priorityString);

    id = arg_id;
    std::istringstream issDateTime(dateTimeLine);
    issDateTime >> date >> time;
    std::istringstream issDefense(defenseString);
    issDefense >> defenseDate >> defenseTime;
    priority = std::stoi(priorityString);
    duration = std::stoi(durationString);
    isPostponable = stringToBool(postponableString);
    level = validateLevel(level);

    return new Orientation(id, date, time, duration, priority, 
                          isPostponable, studentName, level,
                          defenseDate, defenseTime);
}

Event* readEvent(std::ifstream& File, std::string arg_id) {
    std::string id;
    std::string dateTimeLine;
    std::string date;
    std::string time;
    std::string durationString;
    std::string eventName;
    std::string location;
    std::string priorityString;
    int duration;
    int priority;
    
    std::getline(File, dateTimeLine);
    std::getline(File, durationString);
    std::getline(File, eventName);
    std::getline(File, location);
    std::getline(File, priorityString);

    id = arg_id;
    std::istringstream issDateTime(dateTimeLine);
    issDateTime >> date >> time;
    duration = std::stoi(durationString);
    priority = std::stoi(priorityString);
    
    return new Event(id, date, time, duration, priority, eventName, location);
}

DepartmentMeeting* readDepartmentMeeting(std::ifstream& File, std::string arg_id) {
    std::string id;
    std::string dateTimeLine;
    std::string date;
    std::string time;
    std::string durationString;
    std::string postponableString;
    std::string topic;
    std::string priorityString;
    bool isPostponable;
    int duration;
    int priority;
    
    std::getline(File, dateTimeLine);
    std::getline(File, durationString);
    std::getline(File, postponableString);
    std::getline(File, topic);
    std::getline(File, priorityString);

    id = arg_id;
    std::istringstream issDateTime(dateTimeLine);
    issDateTime >> date >> time;
    isPostponable = stringToBool(postponableString);
    duration = std::stoi(durationString);
    priority = std::stoi(priorityString);
    
    return new DepartmentMeeting(id, date, time, duration, priority, isPostponable, topic);
}

Personal* readPersonal(std::ifstream& File, std::string arg_id) {
    std::string id;
    std::string dateTimeLine;
    std::string date;
    std::string time;
    std::string durationString;
    std::string motive;
    std::string postponableString;
    std::string description;
    std::string location;
    std::string priorityString;
    bool isPostponable;
    int duration;
    int priority;
    
    std::getline(File, dateTimeLine);   
    std::getline(File, durationString);
    std::getline(File, postponableString);
    std::getline(File, motive);
    std::getline(File, location);
    std::getline(File, priorityString);

    id = arg_id;
    std::istringstream issDateTime(dateTimeLine);
    issDateTime >> date >> time;
    duration = std::stoi(durationString);
    priority = std::stoi(priorityString);
    isPostponable = stringToBool(postponableString);
    
    return new Personal(id, date, time, duration, priority, isPostponable, description, location, motive);
}

bool stringToBool(std::string& string){

    if (string == "true")
        return true;
    else if (string == "false")
        return false;
    else
        std::cout << "INVALID STRING" << std::endl;
        
    exit(EXIT_FAILURE);    
}

std::string validateLevel(const std::string& level){
    if (level == "Graduação" || level == "Mestrado" || level == "Especialização") {
        return level;
    } else {
        std::cout << "INVALID DEGREE LEVEL [" << level << "]" << std::endl;
        exit(EXIT_FAILURE);
    }
}
