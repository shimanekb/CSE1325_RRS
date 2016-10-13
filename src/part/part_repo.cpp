#include "part/part_repo.hpp"

#include "rss_error.hpp"

bool PartRepo::Add(std::unique_ptr<Part> part) {
    parts.push_back(std::move(part));
    return true;
}

std::vector<std::unique_ptr<Part>> PartRepo::GetAll() {
    std::vector<std::unique_ptr<Part>> tmp_parts;
    for (std::unique_ptr<Part> const &part : parts) {
        tmp_parts.push_back(std::unique_ptr<Part>{part->Clone()});
    }
    return tmp_parts;    
}


int PartRepo::GetByPartNumber(int part_number, std::unique_ptr<Part> &part) {
    int error_code = RssError::NOT_FOUND;
    for (const std::unique_ptr<Part> &tmp_part : parts) {
        if (tmp_part->GetPartNumber() == part_number) {
           part = std::unique_ptr<Part>{tmp_part->Clone()};
           error_code = RssError::NO_ERROR; 
        }
    }
    return error_code;
}
