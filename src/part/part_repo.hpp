#ifndef RSS_PART_PART_REPO_HPP_
#define RSS_PART_PART_REPO_HPP_

#include <vector>
#include "part.hpp"

class PartRepo {
    public:
        bool AddPart(const Part* part);
        vector<Part> GetParts();
        static PartRepo& GetInstance();
    private:
        PartRepo();
        PartRepo(const& PartRepo);
        void operator=(const& PartRepo);
        vector<Part> parts;
};

#endif
