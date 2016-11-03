#ifndef RRS_PART_PART_VIEW_HPP_
#define RRS_PART_PART_VIEW_HPP_

#include <memory>
#include <vector>

#include "part/part.hpp"

class PartView {
    public:
        void DisplayPart(std::unique_ptr<Part> const &part);
        void DisplayParts(std::vector<std::unique_ptr<Part>> const &parts);
};

#endif
