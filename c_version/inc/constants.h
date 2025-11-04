#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdbool.h>

//ALL STRING LENGHT VALUES HAS +1 SIZE FOR \0 OPERAND  

static const int ID_STRING_LENGHT        = 8;   
static const int DATE_STRING_LENGHT      = 11;
static const int TIME_STRING_LENGHT      = 6;
static const int NAME_STRING_LENGHT      = 50;
static const int PLACE_STRING_LENGHT     = 50;
static const int MOTIVE_STRING_LENGHT    = 50;

static const int LESSON_MULTIPLIER       = 2;
static const int ORIENTATION_MULTIPLIER  = 1;
static const int DEPT_MEETING_MULTIPLIER = 4;
static const int EVENTS_MULTIPLIER       = 3;
static const int PERSSONAL_MULTIPLIER    = 2;

static const char BACHELOR[]             = "BACHELOR";
static const char MASTER[]               = "MASTER";
static const char SPECALIZATION[]        = "SPECIALIZATION";

#endif