#ifndef FILE_INPUT_OUTPUT_H
#define FILE_INPUT_OUTPUT_H

#include "../inc/linked_list.h"

int readInputFile(char* file, List* commitmentList);

void processCommitment(char* ID, FILE* file_pointer, List* commitmentList);

int convertToInt(char* charID);

void lineCleaner(char* line);

#endif