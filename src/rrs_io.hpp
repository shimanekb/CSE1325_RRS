#ifndef RRS_RSS_IO_HPP
#define RRS_RSS_IO_HPP

#include <string>

#include "part/part.hpp"

namespace rrs_io {
    int PartTypeIn(Part::PartType &part_type);
    int DoubleIn(double& in);
    int StringIn(std::string& in);
    int IntIn(int& in); 
}

#endif
