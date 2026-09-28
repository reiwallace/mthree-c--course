#ifndef TODO_LIST
#define TODO_LIST

#include "task.h"
#include <stack>
#include <unordered_map>
#include <vector>

class TodoList {
private:
    std::unordered_map<int, Task> todoList;
    std::stack<int> nextId;

public:
    TodoList();

    /**
        Adds task to the Todo List and assigns it an ID
    */
    void addTask(Task& task);

    /**
        Removes a task from the Todo List by ID
    */
    void removeTask(int id);

    /**
        Gets a task from the Todo List from ID
    */
    Task& getTask(int id);

    /**
        Retrieves an immutable list of tasks from the todo list 
    */
    const std::vector<Task> getTasks() const;
};

#endif