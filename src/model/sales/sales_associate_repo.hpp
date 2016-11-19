#ifndef RRS_MODEL_SALES_SALES_ASSOCIATE_REPO_HPP_
#define RRS_MODEL_SALES_SALES_ASSOCIATE_REPO_HPP_

#include <memory>
#include <vector>

#include "model/sales/sales_associate.hpp"

class SalesAssociateRepo {
    public:
        static SalesAssociateRepo& GetInstance() {
            static SalesAssociateRepo instance;
            return instance;
        }
        int SaveSalesAssociate(std::unique_ptr<SalesAssociate> associate);
        int GetAllSalesAssociates(std::vector<std::unique_ptr<SalesAssociate>> &associatesIn);
    private:
        SalesAssociateRepo() {};
        SalesAssociateRepo(SalesAssociateRepo const &);
        void operator=(SalesAssociateRepo const&);
        std::vector<std::unique_ptr<SalesAssociate>> associates;
};

#endif
