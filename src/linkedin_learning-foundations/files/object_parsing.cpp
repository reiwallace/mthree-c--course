#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <stdexcept>
#include <string>

using std::unique_ptr;
using std::string;

class DataObject {
private:
    const string WRITE_DELIMITER = "::";

    int number;
    string name;
    float decimal = 10.5f;

public:
    DataObject(): number(0), name("") {}
    DataObject(int number, const string& name): number(number), name(name) {}

    /**
        Reads a DataOjbect object from the given file name 
        @returns unique pointer to a DataObject from the destination file - Returns nullptr if an error is encountered
    */
    static unique_ptr<DataObject> fromFile(const string& file) {
        std::ifstream inputFile(file);

        // Handle file errors
        if(inputFile.fail()) {
            std::cout << "File not found." << std::endl;
            return nullptr;
        }

        // Get line from file
        string line;
        std::getline(inputFile, line);

        // Split line on a :: delimiter
        std::regex delimiter("::");
        std::sregex_token_iterator iterator(line.begin(), line.end(), delimiter, -1);
        std::sregex_token_iterator end;

        // Parse line
        int number;
        string name;
        float decimal;
        try {
            number = std::stoi(*iterator);
            iterator++;
            name = *iterator;
            iterator++;
            decimal = std::stof(*iterator);
        } catch(std::out_of_range e) {
            std::cout << "Number out of range." << std::endl;
            return nullptr;
        } catch(std::invalid_argument e) {
            std::cout << "Malformed data." << std::endl;
            return nullptr;
        }

    
        // Create object
        unique_ptr<DataObject> data = std::make_unique<DataObject>(number, name);
        data->setDecimal(decimal);

        return data;
    }

    /**
        Sets the float value in the object
    */
    void setDecimal(float decimal) {
        this->decimal = decimal;
    }

    /**
        Writes the object to the destination file
    */
    void writeObject(const string& fileName) const {
        std::ofstream outputFile(fileName);

        if(outputFile.fail()) {
            std::cout << "Error writing to file " << fileName << std::endl;
            return;
        }

        // Write to file
        outputFile << number << WRITE_DELIMITER;
        outputFile << name << WRITE_DELIMITER;
        outputFile << decimal << std::endl;

        outputFile.close();
    }

    /**
        Returns a string containing the contents of the object
    */
    string toString() const {
        return string('{' + std::to_string(number) + ", " + name + ", " + std::to_string(decimal) + "}");
    }
};

int main() {
    const unique_ptr<DataObject> obj = DataObject::fromFile("writeTest.txt");

    // Error code 1 - File error
    if(!obj) {
        return 1;
    }

    std::cout << "Obj: " << obj->toString() << std::endl; 

    return 0;
}