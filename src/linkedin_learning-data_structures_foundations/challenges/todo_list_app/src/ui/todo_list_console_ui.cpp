#include "../../include/ui/todo_list_ui.h"
#include <iostream>
#include <string>


/**
    Displays a task's information to the user
*/
void TodoListUI::viewTask(const Task& task) const {
    std::cout << std::endl;
    std::cout << "================" << std::endl;
    std::cout << "Task: " << task.getName() << std::endl;
    std::cout << "ID: " << task.getId() << std::endl;
    std::cout << "Status: " << (task.isCompleted() ? "Completed" : "Incomplete") << std::endl;
    std::cout << "================" << std::endl;
}

/**
    Asks the user to confirm their action
*/
bool TodoListUI::getConfirmation(const std::string& action) const {
    std::cout << "Are you sure you wish to " << action << "? Y/N" << std::endl;

    // Grab char input from the user
    std::string opt;
    std::getline(std::cin, opt);

    char option = opt[0];
    
    // Return if confirmation char is lower or uppercase y
    return (option == 'y' || option == 'Y');
}

/**
    Displays the option menu to the user
*/
void TodoListUI::viewOptionsMenu() const {
    std::cout << std::endl;
    std::cout << "---OPTIONS---" << std::endl;
    std::cout << "Press..." << std::endl;
    std::cout << "1: Add a new task" << std::endl;
    std::cout << "2: Remove a task" << std::endl;
    std::cout << "3: Toggle a task" << std::endl;
    std::cout << "4: View all tasks" << std::endl;
    std::cout << "5: Exit" << std::endl;
}

/**
    Gets an option menu option
    @returns OPTION enum
*/
OPTION TodoListUI::getMenuOption() const {
    // Retrieve an integer option from the user
    std::string optStr;
    std::getline(std::cin, optStr);
    int opt = std::stoi(optStr);

    // Map option number to option enum
    std::cout << "Option chosen: ";
    switch(opt) {
        case 1:
            std::cout << "Add Task" << std::endl;
            return OPTION::ADD_TASK;

        case 2:
            std::cout << "Remove Task" << std::endl;
            return OPTION::REMOVE_TASK;

        case 3:
            std::cout << "Toggle Task" << std::endl;
            return OPTION::TOGGLE_TASK;

        case 4:
            std::cout << "View Tasks" << std::endl;
            return OPTION::VIEW_TASKS;

        case 5:
            std::cout << "Exiting..." << std::endl;
            return OPTION::EXIT;
        
        default:
            std::cout << "None" << std::endl;
            return OPTION::NO_CHOICE;
    }


}

/**
    Confirms to the user if a task was removed or not
    @param removedTask - The task that was removed. nullptr if not removed.
*/
void TodoListUI::confirmTaskRemoval(const Task* removedTask) const {
    if(removedTask == nullptr) {
        std::cout << "Task not found! Aborting removal..." << std::endl;
    } else {
        std::cout << "Successfully removed task " << removedTask->getName() << std::endl;
    }
}

/**
    Confirms to the user whether the task was toggled
*/
void TodoListUI::confirmTaskToggle(bool status) const {
    std::cout << "Task marked as " << (status ? "Complete" : "Incomplete") << std::endl;
}

/**
    Displays a list of tasks to the user
*/
void TodoListUI::viewTasks(const std::vector<Task>& tasks) const {
    std::cout << "===== CURRENT TODO LIST =====" << std::endl;

    for(const Task& task : tasks) {
        viewTask(task);
    }

    std::cout << std::endl;
}

/**
    Prompts user for task input fields
    @returns a new task from user input
*/
Task TodoListUI::getNewTask() const {
    Task newTask;

    std::cout << std::endl;
    std::cout << "What task are you adding?" << std::endl;

    // Save line to task name and set it in the new task
    std::string taskName = "";
    std::getline(std::cin, taskName);
    newTask.setName(taskName);

    std::cout << "Successfully created task" << std::endl;

    return newTask;
}

/**
    Prompts and retrieves task ID from the user
*/
int TodoListUI::getTaskId() const {
    std::cout << "Please enter a valid task ID" << std::endl;
    
    int id;
    std::string idStr;
    std::getline(std::cin, idStr);
    id = std::stoi(idStr);

    return id;
}
