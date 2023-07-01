//
// Created by sourena khanzadeh on 2023-06-30.
//

#ifndef TASK_TRACKER_TASK_HPP
#define TASK_TRACKER_TASK_HPP

#include <chrono>
#include <string>

struct Task{
    union{
        int id;
        int task_id;
    };
    std::string name;
    std::string description;
    union{
        std::chrono::year_month_day deadline;
        std::chrono::year_month_day task_deadline;
    };
    union{
        bool completed;
        bool task_completed;
    };
};


Task create_task(int id, std::string name, std::string description, std::chrono::year_month_day deadline, bool completed);
void print_task(const Task& task);
Task addRandomDummyTask();
std::string generateRandomString(int n);


#endif //TASK_TRACKER_TASK_HPP
