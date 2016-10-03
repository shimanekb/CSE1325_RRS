#ifndef HEAD_HPP_
#define HEAD_HPP_

#include <string>
#include "part.hpp"

class Head : public Part {
    public:
        Head(const std::string name, const int part_number, 
                const double weight, const double cost, 
                const std::string description, const Part::PartType part_type);
        std::string ToString() const;
};

#endif
