#ifndef TODO_LIST_TASK
#define TODO_LIST_TASK

#include <string>

class Task {
private:
    uint id;
    std::string name;
    bool completed;

public:
    Task();
    Task(const std::string& name);
    Task(bool completed);
    Task(const std::string& name, bool completed);

    void setName(const std::string& name);
    void setId(int id);

    /**
        Toggles completed status
    */
    void toggleCompleted();

    bool isCompleted() const;
    const std::string& getName() const;
    int getId() const;
};

#endif