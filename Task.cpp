#include "task.h"
#include <iostream>

Task::Task(const std::string& t, const std::string& d, int p)
    : title(t), description(d), priority(p) {}

std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
int Task::getPriority() const { return priority; }

void Task::displayTask() const {
    std::cout << "Title: " << title << "\nDescription: " << description
              << "\nPriority: " << priority << std::endl;
}
