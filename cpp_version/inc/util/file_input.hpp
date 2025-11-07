#ifndef FILE_INPUT_OUTPUT_HPP
#define FILE_INPUT_OUTPUT_HPP

#include <iostream>
#include <string>
#include "util/commitment_list.hpp"
#include "classes/lesson.hpp"

int readInputFile(std::string fileName, CommitmentList* commitmentList);

void processCommitment(std::ifstream& File, std::string& textLine, 
                        CommitmentList* commitmentList);

Lesson* readLesson(std::ifstream& File, std::string arg_id);

#endif