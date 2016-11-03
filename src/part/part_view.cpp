#include "part/part_view.hpp" 

#include <iostream>

void PartView::DisplayPart(std::unique_ptr<Part> const &part) {
    std::cout << "Part Information" << std::endl << "*********************" 
        << std::endl << part->ToString() << std::endl;
}

void PartView::DisplayParts(std::vector<std::unique_ptr<Part>> const &parts) {
    int enumerate = 1;
    std::cout << std::endl << "Parts List" << std::endl 
        << "*************************" << std::endl;
    for (std::unique_ptr<Part> const &part : parts) {
        std::cout << enumerate++ << "." << std::endl;
        std::cout << part->ToString();
    }

    std::cout << std::endl;
}
