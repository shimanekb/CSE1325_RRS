#ifndef RRS_CONTROLLER_PART_PART_CONTROLLER_HPP_
#define RRS_CONTROLLER_PART_PART_CONTROLLER_HPP_

#include <memory>

#include "view/part/part_creation_window.hpp"
#include "model/part/part_repo.hpp"
#include "model/part/part.hpp"
#include "model/part/battery.hpp"
#include "model/part/arm.hpp"
#include "model/part/locomotor.hpp"
#include "model/part/torso.hpp"
#include "model/part/head.hpp"
#include "view/part/part_view.hpp"

class PartController {
    public:
        int CreatePart(std::unique_ptr<Part> &partIn, const PartCreationWindow* window);
        int ShowParts();
    private:
        PartView part_view;
        PartRepo &part_repo = PartRepo::GetInstance();
};

#endif
