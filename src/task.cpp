//
// Created by sourena khanzadeh on 2023-06-30.
//

#include <utility>
#include <iostream>
#include <random>
#include "tt/task.hpp"

Task create_task(int id, std::string name, std::string description, std::chrono::year_month_day deadline, bool completed){
    return Task{id, std::move(name), std::move(description), deadline, completed};
}

void print_task(const Task& task){
    std::cout << "Task ID: " << task.id << std::endl;
    std::cout << "Task Name: " << task.name << std::endl;
    std::cout << "Task Description: " << task.description << std::endl;
    std::cout << "Task Deadline: " << static_cast<int>(task.deadline.year())
    << "/" << static_cast<unsigned>(task.deadline.month()) << "/"
    << static_cast<unsigned>(task.deadline.day()) << std::endl;
    std::cout << "Task Completed: " << (task.completed ? "Yes" : "No") << std::endl;
}

Task addRandomDummyTask(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 31);
    std::uniform_int_distribution<> dis2(1, 12);
    std::uniform_int_distribution<> dis3(2021, 2023);
    std::uniform_int_distribution<> dis4(0, 1);
    int id = dis(gen);
    std::string name = generateRandomString(10);
    std::string description = generateRandomString(20);
    int day = dis(gen);
    int month = dis2(gen);
    int year = dis3(gen);
    bool completed = dis4(gen);
    std::chrono::day day_c(day);
    std::chrono::month month_c(month);
    std::chrono::year year_c(year);
    std::chrono::year_month_day deadline(year_c, month_c, day_c);
    Task task = create_task(id, name, description, deadline, completed);
    return task;
}


std::string generateRandomString(int n){
    std::string result;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(97, 122);
    for(int i = 0; i < n; i++)
        result += static_cast<char>(dis(gen));
    return result;
}