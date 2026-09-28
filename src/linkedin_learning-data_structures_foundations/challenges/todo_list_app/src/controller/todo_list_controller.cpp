#include "../../include/controller/todo_list_controller.h"
#include <algorithm>
#include <cstddef>
#include <vector>
    
void TodoController::stop() {
    running = false;
}

TodoController::TodoController() {}

/**
    Injects the TodoList and TodoListUI objects
    @param list - TodoList implementation
    @param ui - TodoListUI implementation
*/
TodoController::TodoController(std::unique_ptr<TodoList> list, std::unique_ptr<TodoListUI> ui): 
list(std::move(list)), ui(std::move(ui)) {}

/**
    Sets the current todo list data access object
*/
void TodoController::setTodoList(std::unique_ptr<TodoList> list) {
    this->list = std::move(list);
}

/**
    Sets the current ui
*/
void TodoController::setUi(std::unique_ptr<TodoListUI> ui) {
    this->ui = std::move(ui);
}

/**
    Starts the controller - Running the options menu and handling the todo list logic
*/
void TodoController::run() {
    running = true;

    while(running) {
        ui->viewOptionsMenu();
        OPTION opt = ui->getMenuOption();

        switch(opt) {
            case OPTION::ADD_TASK:
                addTask();
            break;

            case OPTION::REMOVE_TASK:
                removeTask();
            break;

            case OPTION::TOGGLE_TASK:
                toggleTask();
            break;


            case OPTION::VIEW_TASKS:
                viewTasks();
            break;

            case OPTION::EXIT:
                stop();
            break;

            case OPTION::NO_CHOICE:
            default:
            break;
        }
    }






}

void TodoController::addTask() {
    Task task = ui->getNewTask();
    list->addTask(task);
    ui->viewTask(task);
}

void TodoController::removeTask() {
    int id = ui->getTaskId();
    Task task = list->getTask(id);
    ui->confirmTaskRemoval(&task);
    list->removeTask(id);
}

void TodoController::toggleTask() {
    int id = ui->getTaskId();
    list->getTask(id).toggleCompleted();
}

void TodoController::viewTasks() {
    std::vector<Task> tasks = list->getTasks();
    
    for(Task& task : tasks) {
        ui->viewTask(task);
    }
}