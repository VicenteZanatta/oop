#ifndef FILE_INPUT_OUTPUT_HPP
#define FILE_INPUT_OUTPUT_HPP

#include <iostream>
#include <string>
#include "util/linked_list.hpp"
#include "classes/lesson.hpp"

int readInputFile(std::string fileName, List* commitmentList);

void processCommitment(std::ifstream& File, std::string& textLine, 
                        List* commitmentList);

Lesson* readLesson(std::ifstream& File, std::string arg_id);

#endif