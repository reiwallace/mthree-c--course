#ifndef TODO_CONTROLLER
#define TODO_CONTROLLER

#include "../data/todo_list.h"
#include "../ui/todo_list_ui.h"
#include <memory>

class TodoController {
private:
    std::unique_ptr<TodoList> list;
    std::unique_ptr<TodoListUI> ui;
    bool running;

    void stop();

    /**
        Remove task menu option.
        Tasks user choice and removes task from the list.
    */
    void removeTask();

    /**
        Takes user input to generate a task then adds it to the list
    */
    void addTask();

    /**
        Toggles a task from completed to incomplete and vice versa
    */
    void toggleTask();

    /**
        Grabs a list of tasks and passes it to the ui
    */
    void viewTasks();

public:
    TodoController();
    
    /**
        Injects the TodoList and TodoListUI objects
        @param list - TodoList implementation
        @param ui - TodoListUI implementation
    */
    TodoController(std::unique_ptr<TodoList> list, std::unique_ptr<TodoListUI> ui);

    /**
        Sets the current todo list data access object
    */
    void setTodoList(std::unique_ptr<TodoList> list);

    /**
        Sets the current ui
    */
    void setUi(std::unique_ptr<TodoListUI> ui);

    /**
        Starts the controller - Running the options menu and handling the todo list logic
    */
    void run();
};

#endif