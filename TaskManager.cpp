#include "TaskManager.h"
#include <iostream>

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
    actionHistory.push("Added Task: " + task.getTitle());
    std::cout << "Task added successfully.\n";
}

void TaskManager::removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        actionHistory.push("Removed Task: " + tasks[index].getTitle());
        tasks.erase(tasks.begin() + index);
        std::cout << "Task removed successfully.\n";
    } else {
        std::cout << "Invalid task index.\n";
    }
}

void TaskManager::undoLastAction() {
    if (!actionHistory.empty()) {
        std::cout << "Undoing: " << actionHistory.top() << std::endl;
        actionHistory.pop();
    } else {
        std::cout << "No actions to undo.\n";
    }
}

void TaskManager::addToQueue(const Task& task) {
    taskQueue.push(task);
    std::cout << "Task added to processing queue.\n";
}

void TaskManager::processNextTask() {
    if (!taskQueue.empty()) {
        Task task = taskQueue.front();
        taskQueue.pop();
        std::cout << "Processing task:\n";
        task.displayTask();
    } else {
        std::cout << "No tasks in the queue to process.\n";
    }
}

void TaskManager::listTasks() const {
    std::cout << "Listing all tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "Task " << i + 1 << ":\n";
        tasks[i].displayTask();
    }
}
