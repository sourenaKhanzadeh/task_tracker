#include "tt/frontend.hpp"

int main() {
    fe::init();
    while(true){
        fe::print_menu();
        int choice;
        std::cin >> choice;
        if(choice == 1)
            fe::new_task();
        else if(choice == 2){
            fe::view_all_tasks();
            std::cout << "Press enter to continue...\n";
            std::cin.ignore();
            std::cin.get();
        }
        else if(choice == 3)
        {
            std::cout << "Enter filter name: ";
            std::string filter_name;
            std::cin >> filter_name;
            fe::filter_tasks(get_filter(filter_name));
        }
        else if(choice == 4)
            fe::sort_tasks();
        else if(choice == 5)
            fe::mark_task_as_completed();
        else if(choice == 6){
            fe::exit();
            break;
        }
        else
            std::cout << "Invalid choice!" << std::endl;

    }

    return 0;
}
