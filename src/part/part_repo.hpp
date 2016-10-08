#ifndef RSS_PART_PART_REPO_HPP_
#define RSS_PART_PART_REPO_HPP_

#include <vector>
#include <memory>
#include "part.hpp"

class PartRepo {
    public:
        bool Add(std::unique_ptr<Part> part);
        const std::vector<std::unique_ptr<Part>>& GetAll();
        int GetByPartNumber(int part_number, std::unique_ptr<Part> &part);
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
