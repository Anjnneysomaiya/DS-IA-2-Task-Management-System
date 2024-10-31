#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <stack>
#include <queue>
#include "task.h"

class TaskManager {
private:
    std::vector<Task> tasks;
    std::stack<std::string> actionHistory;
    std::queue<Task> taskQueue;

public:
    void addTask(const Task& task);
    void removeTask(int index);
    void undoLastAction();
    void addToQueue(const Task& task);
    void processNextTask();
    void listTasks() const;
};

#endif // TASKMANAGER_H
