#include "../../include/data/todo_list.h"
#include <cstddef>
#include <unordered_map>

TodoList::TodoList() {
    nextId.push(1);
}

/**
    Adds task to the Todo List and assigns it an ID
*/
void TodoList::addTask(Task& task) {
    int taskId = nextId.top();
    task.setId(taskId);
    todoList.insert({taskId, task});
    nextId.pop();

    if(nextId.empty()) {
        nextId.push(taskId + 1);
    }
}

/**
    Removes a task from the Todo List by ID
*/
void TodoList::removeTask(int id) {
    todoList.erase(id);
    nextId.push(id);
}

/**
    Gets a task from the Todo List from ID
*/
Task& TodoList::getTask(int id) {
    return todoList.at(id);
}

/**
    Retrieves an immutable list of tasks from the todo list 
*/
const std::vector<Task> TodoList::getTasks() const {
    std::vector<Task> list;

    for(auto iter = todoList.begin(); iter != todoList.end(); iter++) {
        list.push_back(iter->second);
    }

    return list;
}
