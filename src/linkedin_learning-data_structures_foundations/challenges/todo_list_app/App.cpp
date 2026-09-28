#include "include/controller/todo_list_controller.h"
#include "include/data/todo_list.h"
#include "include/ui/todo_list_ui.h"
#include <memory>

int main() {
    std::unique_ptr<TodoList> todoList = std::make_unique<TodoList>();
    std::unique_ptr<TodoListUI> ui = std::make_unique<TodoListUI>();

    TodoController controller = TodoController(std::move(todoList), std::move(ui));

    controller.run();

    return 0;
}