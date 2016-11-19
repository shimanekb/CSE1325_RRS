#include "model/sales/sales_associate_repo.hpp"

#include "rrs_error.hpp"

int SalesAssociateRepo::SaveSalesAssociate(
        std::unique_ptr<SalesAssociate> associate) {
   int errorCode = RrsError::NO_ERROR; 

   associates.push_back(std::unique_ptr<SalesAssociate>{std::move(associate)});

   return errorCode;
}

int SalesAssociateRepo::GetAllSalesAssociates(
        std::vector<std::unique_ptr<SalesAssociate>> &associatesIn) {
   int errorCode = RrsError::NO_ERROR; 

   associatesIn.clear();
   for (const std::unique_ptr<SalesAssociate> &tmpAssociate : associates) {
       associatesIn.push_back(
               std::unique_ptr<SalesAssociate>{tmpAssociate->Clone()});
   }

   return errorCode;
}

int SalesAssociateRepo::GetSalesAssociateByNumber(
        int number, std::unique_ptr<SalesAssociate> &associateIn) {
    int errorCode = RrsError::NOT_FOUND;
    
    for (const std::unique_ptr<SalesAssociate> &tmpAssociate : associates) {
        if (tmpAssociate->GetEmployeeNumber() == number) {
            errorCode = RrsError::NO_ERROR;
            associateIn = std::unique_ptr<SalesAssociate>{tmpAssociate->Clone()};
        }
    }

    return errorCode;
}
