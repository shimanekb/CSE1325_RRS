#ifndef RRS_MODEL_PART_HEAD_HPP_
#define RRS_MODEL_PART_HEAD_HPP_

#include <string>

#include "model/part/part.hpp"

class Head : public Part {
    public:
        Head(const std::string name, const int part_number, 
                const double weight, const double cost, 
                const std::string description);
        std::string ToString() const;
        Part* Clone() const;
};

#endif
