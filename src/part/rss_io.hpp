#ifndef RSS_IO_HPP
#define RSS_IO_HPP

#include <string>
#include "part.hpp"

namespace rss_io {
    int PartTypeIn(Part::PartType &part_type);
    int DoubleIn(double& in);
    int StringIn(std::string& in);
    int IntIn(int& in); 
}

#endif
