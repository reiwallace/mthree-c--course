#include <iostream>
#include <map>
#include <string>
#include <variant>

int main() {
    std::map<std::string, std::variant<std::string, int, double, bool>> dict;
    dict["currency"] = "USD";
    dict["enableLocation"] = false;
    dict["volumeLevel"] = 80;
    dict["dateFormat"] = "MM/DD/YYYY";

    dict["volumeLevel"] = static_cast<int>(std::get<int>(dict.at("volumeLevel")) * 0.5);

    std::cout << "Updated volume level: " << std::get<int>(dict.at("volumeLevel")) << std::endl;
}