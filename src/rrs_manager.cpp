#include "rrs_manager.hpp"

#include "rss_io.hpp"
#include "rss_error.hpp"

int RrsManager::execute() {
    return MainMenu();
}

int RrsManager::MainMenu() {
    int error_code = RssError::NO_ERROR;
    bool do_not_exit = true;
    int selection;

    while(do_not_exit) {
       rrs_view.DisplayMainMenu();
       error_code = rss_io::IntIn(selection);

       if (error_code || selection < 1 || selection > 3)
           rrs_view.DisplayBadSelectionMessage();
       else
           switch(selection) {
               case 1:
                   //create
                   CreateMenu();
                   break;
               case 2:
                   //report
                   ReportMenu();
                   break;
               case 3:
                   //quit
                   do_not_exit = false;
                   break;
           }
    }

    return error_code;
}

int RrsManager::ReportMenu() {
    int error_code = RssError::NO_ERROR;
    bool do_not_exit = true;
    int selection;

    while(do_not_exit) {
       rrs_view.DisplayReportMenu();
       error_code = rss_io::IntIn(selection);

       if (error_code || selection < 1 || selection > 3)
           rrs_view.DisplayBadSelectionMessage();
       else
           switch(selection) {
               case 1:
                   //robot model
                   error_code = robot_controller.ShowRobots();
                   break;
               case 2:
                   //robot parts
                   error_code = part_controller.ShowParts();
                   break;
               case 3:
                   //quit main menu
                   do_not_exit = false;
                   break;
           }
    }

    return error_code;

}

int RrsManager::CreateMenu() {
    int error_code = RssError::NO_ERROR;
    bool do_not_exit = true;
    int selection;

    while(do_not_exit) {
       rrs_view.DisplayCreateMenu();
       error_code = rss_io::IntIn(selection);

       if (error_code || selection < 1 || selection > 3)
           rrs_view.DisplayBadSelectionMessage();
       else
           switch(selection) {
               case 1:
                   //robot model
                   error_code = robot_controller.CreateRobot();
                   break;
               case 2:
                   //robot parts
                   error_code = part_controller.CreatePart();
                   break;
               case 3:
                   //quit main menu
                   do_not_exit = false;
                   break;
           }
    }

    return error_code;
}
