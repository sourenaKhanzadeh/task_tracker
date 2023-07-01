//
// Created by sourena khanzadeh on 2023-06-30.
//

#include "tt/frontend.hpp"

std::string multi_generator(int n, std::string s) {
    std::string result;
    for(int i = 0; i < n; i++)
        result += s;
    return result;
}

void fe::print_menu() {
    std::cout << "==== Task Tracker ====" << std::endl;
    std::cout << "1. Add a new task" << std::endl;
    std::cout << "2. View all A" << std::endl;
    std::cout << "3. Filter A" << std::endl;
    std::cout << "4. Sort A" << std::endl;
    std::cout << "5. Mark task as completed" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << multi_generator(22, "=") << std::endl;
}


void fe::exit() {
    std::cout << "Goodbye!" << std::endl;
}

void fe::new_task() {
    std::cout << "new task" << std::endl;
    int id;
    std::string name;
    std::string description;
    int day, month, year;
    bool completed;
    std::cout << "Enter task ID: ";
    std::cin >> id;
    std::cout << "Enter task name: ";
    std::cin >> name;
    std::cout << "Enter task description: ";
    std::cin >> description;
    std::cout << "Enter task deadline: ";
    std::cin >> day >> month >> year;

    std::chrono::day day_c(day);
    std::chrono::month month_c(month);
    std::chrono::year year_c(year);

    std::chrono::year_month_day deadline(year_c, month_c, day_c);

    std::cout << "Enter task completed: ";
    std::cin >> completed;
    Task task = create_task(id, name, description, deadline, completed);
    ALL_TASKS.push_back(task);
}

void fe::view_all_tasks() {
    std::cout << "view all" << std::endl;
    for(auto& task : ALL_TASKS){
        std::cout << multi_generator(20, "=") << std::endl;
        print_task(task);
        std::cout << multi_generator(20, "=") << std::endl;
    }
}

void fe::filter_tasks(const std::function<bool(const Task&)>& filter) {
    std::cout << "filter" << std::endl;
    for(auto& task : ALL_TASKS){
        if(filter(task)){
            std::cout << multi_generator(20, "=") << std::endl;
            print_task(task);
            std::cout << multi_generator(20, "=") << std::endl;
        }
    }
}

std::function<bool(const Task&)> get_filter(const std::string& filter_name) {
    std::cout << "get filter" << std::endl;
    if (filter_name == "completed")
        return [](const Task& task){return task.completed;};
    else if (filter_name == "incomplete")
        return [](const Task& task){return !task.completed;};
    else if (filter_name == "overdue")
        return [](const Task& task){
            return std::chrono::sys_days (task.deadline) < std::chrono::system_clock::now();
    };
    else if (filter_name == "today")
        return [](const Task& task){return std::chrono::sys_days (task.deadline) == std::chrono::system_clock::now();};
    else if (filter_name == "this week")
        return [](const Task& task){return std::chrono::sys_days (task.deadline) < std::chrono::system_clock::now() + std::chrono::days(7);};
    else if (filter_name == "this month")
        return [](const Task& task){return std::chrono::sys_days (task.deadline) < std::chrono::system_clock::now() + std::chrono::days(30);};
    else if (filter_name == "this year")
        return [](const Task& task){return std::chrono::sys_days (task.deadline) < std::chrono::system_clock::now() + std::chrono::days(365);};
    else if (filter_name == "all")
        return [](const Task& task){return true;};
    else if (filter_name == "none")
        return [](const Task& task){return false;};
    else if (filter_name == "exit")
        return [](const Task& task){return false;};
    else if (filter_name == "back")
        return [](const Task& task){return false;};
    else
    return nullptr;
}

void fe::sort_tasks() {
    std::cout << "sort" << std::endl;
    std::cout << "1. Sort by ID" << std::endl;
    std::cout << "2. Sort by name" << std::endl;
    std::cout << "3. Sort by deadline" << std::endl;
    std::cout << "4. Sort by completed" << std::endl;
    std::cout << "5. Back" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << multi_generator(22, "=") << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::sort(ALL_TASKS.begin(), ALL_TASKS.end(), [](const Task& a, const Task& b){return a.id < b.id;});
            break;
        case 2:
            std::sort(ALL_TASKS.begin(), ALL_TASKS.end(), [](const Task& a, const Task& b){return a.name < b.name;});
            break;
        case 3:
            std::sort(ALL_TASKS.begin(), ALL_TASKS.end(), [](const Task& a, const Task& b){return a.deadline < b.deadline;});
            break;
        case 4:
            std::sort(ALL_TASKS.begin(), ALL_TASKS.end(), [](const Task& a, const Task& b){return a.completed < b.completed;});
            break;
        case 5:
            return;
        case 6:
            exit();
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
    }
}

void fe::mark_task_as_completed() {
    std::cout << "mark task as completed" << std::endl;
    int id;
    std::cout << "Enter task ID: ";
    std::cin >> id;
    for(auto& task : ALL_TASKS){
        if(task.id == id){
            task.completed = true;
            return;
        }
    }
}

void fe::init() {
    std::cout << "init" << std::endl;
    for (int i = 0; i < 20; ++i) {
        Task task = addRandomDummyTask();
        ALL_TASKS.push_back(task);
    }
}

