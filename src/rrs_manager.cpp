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
                   rrs_view.DisplayCreateMenu();
                   break;
               case 2:
                   //report
                   rrs_view.DisplayReportMenu();
                   break;
               case 3:
                   //quit
                   do_not_exit = false;
                   break;
           }
    }

    return error_code;
}
