#ifndef RRS_PART_PART_CONTROLLER_HPP_
#define RRS_PART_PART_CONTROLLER_HPP_

#include <memory>

#include "part/view/part_creation_window.hpp"
#include "part/part_repo.hpp"
#include "part/part.hpp"
#include "part/battery.hpp"
#include "part/arm.hpp"
#include "part/locomotor.hpp"
#include "part/torso.hpp"
#include "part/head.hpp"
#include "part/part_view.hpp"

class PartController {
    public:
        int CreatePart(std::unique_ptr<Part> &partIn, const PartCreationWindow* window);
        int ShowParts();
    private:
        PartView part_view;
        PartRepo &part_repo = PartRepo::GetInstance();
};

#endif
