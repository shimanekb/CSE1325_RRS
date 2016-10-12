#include "generic_validation_strategy.hpp"

#include <memory>

#include "rss_error.hpp"
#include "torso.hpp"

GenericValidationStrategy::GenericValidationStrategy(int max) : kMax(max) {};

int GenericValidationStrategy::Validate(const Robot &robot, const Part &part) {
    int error_code = RssError::OUT_OF_RANGE;
    constexpr int kPartMax = 1;
    int part_count = 1;


    for(std::unique_ptr<Part> const &tmp_part : robot.GetParts()) {
        if(tmp_part->GetPartType() == part.GetPartType()) {
            ++part_count;
        }

    }
     
    if (part_count <= kPartMax) {
       error_code = RssError::NO_ERROR; 
    }
    return error_code;
}
