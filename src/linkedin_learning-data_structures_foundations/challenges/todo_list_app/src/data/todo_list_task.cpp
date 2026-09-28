#include "../../include/data/task.h"

Task::Task() {}
Task::Task(const std::string& name): name(name) {}
Task::Task(bool completed): completed(completed) {}
Task::Task(const std::string& name, bool completed): name(name), completed(completed) {}

void Task::setName(const std::string& name) {
    this->name = name;
}

void Task::setId(int id) {
    this->id = id;
}

/**
    Toggles completed status
*/
void Task::toggleCompleted() {
    completed = !completed;
}

bool Task::isCompleted() const {
    return completed;
}

const std::string& Task::getName() const {
    return name;
}

int Task::getId() const {
    return id;
}
