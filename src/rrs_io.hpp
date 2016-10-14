#ifndef RRS_RSS_IO_HPP_
#define RRS_RSS_IO_HPP_

#include <string>

#include "part/part.hpp"

namespace rrs_io {
    int PartTypeIn(Part::PartType &part_type);
    int DoubleIn(double& in);
    int StringIn(std::string& in);
    int IntMinMaxIn(int& in, int min, int max); 
    int IntIn(int& in); 
}

#endif
