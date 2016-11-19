#include "controller/sales/sales_controller.hpp"

#include <string>

#include "rrs_error.hpp"
#include "rrs_io.hpp"

int SalesController::CreateSalesAssociate(std::unique_ptr<SalesAssociate> &associateIn,
    const SalesCreationWindow *window) {
    constexpr int kMax = 99999999999;
    int errorCode = RrsError::NO_ERROR; int employeeNumber;
    std::string employeeNumberStr = window->GetEmployeeNumber();
    std::string name = window->GetName();;
    
    errorCode = rrs_io::StringToInt(employeeNumberStr, employeeNumber,
            1, kMax);

    if (!(errorCode && name.empty())) {
        SalesAssociate *associate = new SalesAssociate{name, employeeNumber};    
        associateIn = std::unique_ptr<SalesAssociate>{associate->Clone()};
        errorCode = salesRepo.SaveSalesAssociate(std::unique_ptr<SalesAssociate>{associate});
    }

    return errorCode;
}

int SalesController::GetSalesAssociates(std::vector<std::unique_ptr<SalesAssociate>> 
        &associatesIn) {
    return salesRepo.GetAllSalesAssociates(associatesIn);
}

