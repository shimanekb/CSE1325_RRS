#ifndef RRS_RSS_IO_HPP_
#define RRS_RSS_IO_HPP_

#include <string>

#include "model/part/part.hpp"

namespace rrs_io {
    int PartTypeIn(Part::PartType &part_type);
    int DoubleIn(double& in);
    int StringIn(std::string& in);
    int IntMinMaxIn(int& in, int min, int max); 
    int IntIn(int& in); 
    int StringToDouble(std::string in, double &out, int min, int max);
    int StringToInt(std::string in, int &out,int min, int max);
    Part::PartType PartTypeByIndex(int index);
}

#endif
