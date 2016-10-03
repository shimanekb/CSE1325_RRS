#include "part_repo.hpp"

bool PartRepo::Add(std::unique_ptr<const Part> part) {
    parts.push_back(std::move(part));
    return true;
}

const std::vector<std::unique_ptr<const Part>>& PartRepo::GetAll() {
    return parts;    
}
