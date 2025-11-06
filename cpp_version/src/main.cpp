#include <iostream>
#include "util/linked_list.hpp"
#include "util/file_input_output.hpp"
//#include "util/report_generator.hpp"

std::string const INPUT_FILE_NAME = "agenda.txt";

int main(){
    List* commitmentList = new List();

    if (readInputFile(INPUT_FILE_NAME, commitmentList) != 0) {
        std::cout << "Failed to read input file!" << std::endl;
        delete commitmentList;
        return 1;
    }

    // Generate reports
    //ReportGenerator::generateAllReports(commitmentList);

    commitmentList->printList();

    delete commitmentList;
    return 0;
}