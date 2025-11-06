#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "classes/lesson.hpp"
#include "classes/commitment.hpp"
#include "util/linked_list.hpp"
#include "util/file_input_output.hpp"
#include "classes/orientation.hpp"

bool stringToBool(std::string& );
std::string validateLevel(const std::string&);
Lesson* readLesson(std::ifstream& File, std::string arg_id);
Orientation* readOrientation(std::ifstream& File, std::string arg_id);

int readInputFile(std::string fileName, List* commitmentList){

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

void processCommitment(std::ifstream& File, std::string& textLine, List* commitmentList)
{
    char commitmentType = textLine[0];

    switch(commitmentType){ 
        case 'A':                    
            commitmentList->addNode(readLesson(File, textLine));
            break;
        case 'O':
            commitmentList->addNode(readOrientation(File, textLine));
            break;
        default:    
            std::cout << "TYPE [" << textLine[0] << "] NOT KNOWN" << std::endl; 
            exit(EXIT_FAILURE);
            break;    
    }
}

Lesson* readLesson(std::ifstream& File, std::string arg_id)
{
    std::string id;
    std::string dateTimeLine; // used to store line with date and line 
    std::string date;
    std::string time;
    std::string durationString;
    std::string priorityString;
    std::string subject;
    std::string level;
    int duration;
    int priority;
    
    id = arg_id; 
    
    std::getline(File, dateTimeLine);
    std::istringstream iss(dateTimeLine);   // functio that copie word by word from a line 
    iss >> date >> time;
    std::getline(File, durationString);
    duration = std::stoi(durationString);
    std::getline(File, subject);
    std::getline(File, level);
    std::getline(File, priorityString);
    priority = std::stoi(priorityString);

    level = validateLevel(level);
    
    Lesson* lesson = new Lesson(id, date, time, duration, priority, subject, level);

    return lesson;
}

Orientation* readOrientation(std::ifstream& File, std::string arg_id)
{
    std::string id;
    std::string dateTimeLine; // used to store line with date and line 
    std::string date;
    std::string time;
    std::string durationString;
    std::string priorityString;
    std::string postponableString;
    std::string studentName;
    std::string level;
    bool isPostponable;
    int duration;
    int priority;
    
    id = arg_id; 
    
    std::getline(File, dateTimeLine);
    std::istringstream iss(dateTimeLine);   // functio that copie word by word from a line 
    iss >> date >> time;
    std::getline(File, durationString);
    duration = std::stoi(durationString);
    std::getline(File, postponableString);
    isPostponable = stringToBool(postponableString);
    std::getline(File, studentName);
    std::getline(File, level);
    std::getline(File, priorityString);
    priority = std::stoi(priorityString);

    level = validateLevel(level);

    Orientation* orientation = new Orientation(id, date, time, duration, priority, 
                                                isPostponable, studentName, level);
    return orientation;
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
    if (level == "Graduação" || level == "Mestrado" || level == "Doutorado") {
        return level;
    } else {
        std::cout << "INVALID DEGREE LEVEL [" << level << "]" << std::endl;
        exit(EXIT_FAILURE);
    }
}
