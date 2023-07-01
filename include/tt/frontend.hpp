//
// Created by sourena khanzadeh on 2023-06-30.
//

#ifndef TASK_TRACKER_FRONTEND_HPP
#define TASK_TRACKER_FRONTEND_HPP

//==== Task Tracker ====
//
//1. Add a new task
//2. View all A
//3. Filter A
//4. Sort A
//5. Mark task as completed
//6. Exit
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "tt/task.hpp"


std::string multi_generator(int n, std::string s);

namespace frontend{
    static std::vector<Task> ALL_TASKS;
    void init();
    void print_menu();
    void new_task();
    void view_all_tasks();
    void filter_tasks(const std::function<bool(const Task&)>& filter);
    void sort_tasks();
    void mark_task_as_completed();
    void exit();
};

std::function<bool(const Task&)> get_filter(const std::string& filter_name);


namespace fe = frontend;



#endif //TASK_TRACKER_FRONTEND_HPP
