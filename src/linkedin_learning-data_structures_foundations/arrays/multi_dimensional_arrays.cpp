#include <iostream>
#include <iterator>
#include <string>

int main() {
    std::string seating_chart[4][5] = {
        {"Sarah", "Claire", "Ben", "Taylor", "Eva"},
        {"Frankie", "George", "Lindsey", "Izzy", "Jack"},
        {"Katherine", "Lauren", "Mary", "Nathen", "Olive"},
        {"Chad", "April", "Matt", "Thomas", "Penny"}
    };

    // Accessing student on row 3, seat 2
    //std::cout << seating_chart[2][1] << std::endl << std::endl;

    // Outputting all rows and their students
    // Calculate number of items in the initial array
    for(int row = 0; row < sizeof(seating_chart) / sizeof(*seating_chart); row++) {
        std::cout << "Row: " << row + 1 << ", Students: ";
        
        // Calculate the number of items in each row
        int rowSize = sizeof(seating_chart[row]) / sizeof(*seating_chart[row]);
        for(int student = 0; student < rowSize; student++) {

            // Print the current student
            std::cout << seating_chart[row][student];

            // If the student isn't the second to last student add a ', '
            if(student != rowSize - 1) {
                std::cout << ", ";
            }
        }

        std::cout << std::endl << std::endl;
    }


    // Outputting all students from the table
    for(int seat = 0; seat < 20; seat++) {
        std::cout << "Row: " << (seat / 5) + 1 << std::endl;
        std::cout << "Seat: " << (seat % 5) + 1 << std::endl;
        std::cout << "Student name: " << *(*(seating_chart) + seat) << std::endl;
        std::cout << std::endl;
    }
}