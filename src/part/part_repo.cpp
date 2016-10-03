#include "part_repo.hpp"

bool PartRepo::AddPart(std::unique_ptr<const Part> part) {
    parts.push_back(std::move(part));
    return true;
}

/*
const std::vector<std::unique_ptr<const Part>> PartRepo::GetParts() {
    return parts;    
}
*/
