#include "rrs_manager_view.hpp"

#include <iostream>


void RrsManagerView::DisplayMainMenu() {
    std::cout << std::endl << "Main Menu" << std::endl 
        << "***********************" 
        << std::endl << "1. Create" << std::endl << "2. Report" << std::endl
        << "3. Quit" <<std::endl;
}

void RrsManagerView::DisplayCreateMenu() {
    std::cout << std::endl << "Create Menu" << std::endl 
        << "***********************" << std::endl << "1. Robot Model" 
        << std::endl << "2. Robot Component" << std::endl << "3. Robot Order"
        <<std::endl << "4. Quit/Main Menu"
        << std::endl;
}

void RrsManagerView::DisplayReportMenu() {
    std::cout << std::endl << "Report Menu" << std::endl 
        << "***********************" << std::endl << "1. Robot Models" 
        << std::endl << "2. Robot Parts" << std::endl << "3. Quit/Main Menu"
        << std::endl;
}

void RrsManagerView::DisplayBadSelectionMessage() {
    std::cout << "Bad selection input." << std::endl;
}

