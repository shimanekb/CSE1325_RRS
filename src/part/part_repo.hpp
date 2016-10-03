#ifndef RSS_PART_PART_REPO_HPP_
#define RSS_PART_PART_REPO_HPP_

#include <vector>
#include <memory>
#include "part.hpp"

class PartRepo {
    public:
        bool AddPart(std::unique_ptr<const Part> part);
        //const std::vector<std::unique_ptr<const Part>> GetParts();
        static PartRepo& GetInstance() {
            static PartRepo instance;
            return instance;
        }
    private:
        PartRepo() {};
        PartRepo(PartRepo const&);
        void operator=(PartRepo const&);
        std::vector<std::unique_ptr<const Part>> parts;
};
#endif
