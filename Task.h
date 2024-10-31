#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    std::string title;
    std::string description;
    int priority;

public:
    Task(const std::string& t, const std::string& d, int p);
    std::string getTitle() const;
    std::string getDescription() const;
    int getPriority() const;
    void displayTask() const;
};

#endif // TASK_H
