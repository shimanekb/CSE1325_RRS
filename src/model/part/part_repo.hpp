#ifndef RSS_MODEL_PART_PART_REPO_HPP_
#define RSS_MODEL_PART_PART_REPO_HPP_

#include <vector>
#include <memory>

#include "model/part/part.hpp"

class PartRepo {
    public:
        bool Add(std::unique_ptr<Part> part);
        int GetByPartNumber(int part_number, std::unique_ptr<Part> &part);
        std::vector<std::unique_ptr<Part>> GetAll();
        int GetRobotComponentsByType(Part::PartType type, 
                std::vector<std::unique_ptr<Part>> &parts);
        static PartRepo& GetInstance() {
            static PartRepo instance;
            return instance;
        }
    private:
        PartRepo() {};
        PartRepo(PartRepo const&);
        void operator=(PartRepo const&);
        std::vector<std::unique_ptr<Part>> parts;
};
#endif
