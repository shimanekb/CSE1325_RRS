#ifndef RRS_CONTROLLER_SALES_SALES_CONTROLLER_HPP_
#define RRS_CONTROLLER_SALES_SALES_CONTROLLER_HPP_

#include <memory>
#include <vector>

#include "view/sales/sales_creation_window.hpp"
#include "model/sales/sales_associate.hpp"
#include "model/sales/sales_associate_repo.hpp"

class SalesController {
    public:
        int CreateSalesAssociate(std::unique_ptr<SalesAssociate> &associateIn,
                const SalesCreationWindow *window);
        int GetSalesAssociates(std::vector<std::unique_ptr<SalesAssociate>> 
                &associatesIn);
    private:
        SalesAssociateRepo &salesRepo = SalesAssociateRepo::GetInstance();
};

#endif
