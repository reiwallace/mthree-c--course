#ifndef TODO_LIST_UI
#define TODO_LIST_UI

#include "../data/task.h"
#include <string>
#include <vector>

enum class OPTION {
    ADD_TASK,
    REMOVE_TASK,
    TOGGLE_TASK,
    VIEW_TASKS,
    EXIT,
    NO_CHOICE
};

class TodoListUI {
private:
    /**
        Asks the user to confirm their action
    */
    bool getConfirmation(const std::string& action) const;
public:
    /**
        Displays the option menu to the user
    */
    void viewOptionsMenu() const;
    
    /**
        Gets an option menu option
        @returns OPTION enum
    */
    OPTION getMenuOption() const;

    /**
        Confirms to the user if a task was removed or not
        @param removedTask - The task that was removed. nullptr if not removed.
    */
    void confirmTaskRemoval(const Task* removedTask) const;

    /**
        Confirms to the user whether the task was toggled
    */
    void confirmTaskToggle(bool status) const;

    /**
        Displays a list of tasks to the user
    */
    void viewTasks(const std::vector<Task>& tasks) const;

    /**
        Prompts user for task input fields
        @returns a new task from user input
    */
    Task getNewTask() const;

    /**
        Prompts and retrieves task ID from the user
    */
    int getTaskId() const;

    /**
        Displays a task's information to the user
    */
    void viewTask(const Task& task) const;
};

#endif