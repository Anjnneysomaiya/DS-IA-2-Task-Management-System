#include <iostream>
#include "TaskManager.h"

void displayMenu() {
    std::cout << "\nTask Manager Menu:\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. List Tasks\n";
    std::cout << "4. Undo Last Action\n";
    std::cout << "5. Add Task to Queue\n";
    std::cout << "6. Process Next Task in Queue\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    TaskManager manager;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();
                std::string title, description;
                int priority;

                std::cout << "Enter task title: ";
                std::getline(std::cin, title);
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                std::cout << "Enter task priority: ";
                std::cin >> priority;

                Task task(title, description, priority);
                manager.addTask(task);
                break;
            }
            case 2: {
                int index;
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                manager.removeTask(index - 1);
                break;
            }
            case 3:
                manager.listTasks();
                break;
            case 4:
                manager.undoLastAction();
                break;
            case 5: {
                std::cin.ignore();
                std::string title, description;
                int priority;

                std::cout << "Enter task title for queue: ";
                std::getline(std::cin, title);
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                std::cout << "Enter task priority: ";
                std::cin >> priority;

                Task task(title, description, priority);
                manager.addToQueue(task);
                break;
            }
            case 6:
                manager.processNextTask();
                break;
            case 0:
                std::cout << "Exiting Task Manager.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
