#ifndef RRS_PART_HEAD_HPP_
#define RRS_PART_HEAD_HPP_

#include <string>
#include "part.hpp"

class Head : public Part {
    public:
        Head(const std::string name, const int part_number, 
                const double weight, const double cost, 
                const std::string description);
        std::string ToString() const;
};

#endif