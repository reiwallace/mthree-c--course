#include <iostream>
#include <string>
#include <unordered_map>

void adjustSalary(std::unordered_map<std::string, int> &employees_salaries, const std::string &name, double adjustment) {
    employees_salaries[name] = static_cast<int>(employees_salaries.at(name) * (1 + adjustment));
}

int main() {
    std::unordered_map<std::string, int> salaries;
    salaries.emplace("John", 20000);
    salaries.emplace("Sarah", 25000);
    salaries.emplace("Rick", 30000);
    salaries.emplace("Emma", 32500);

    const std::string SALARY_TARGET = "Emma"; 

    std::cout << SALARY_TARGET << " salary (before raise): " << salaries.at(SALARY_TARGET) << std::endl;

    adjustSalary(salaries, SALARY_TARGET, 0.4);

    std::cout << SALARY_TARGET << " salary (after raise): " << salaries.at(SALARY_TARGET) << std::endl;

    return 0;
}