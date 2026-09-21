#include <iostream>

int main() {
    // Define array and get number of students
    int booksArr[] = {5, 3, 0, 7, 2, 4, 6, 8, 1, 3, 9, 5, 2, 6, 7, 4};
    int numStudents = sizeof(booksArr) / sizeof(*booksArr);

    std::cout << "Total students: " << numStudents << std::endl;

    
    // Modifying list
    booksArr[0] = 8;
    booksArr[1] += 1;
    booksArr[numStudents - 1] += 2;


    // Calculate average books read per student
    int total = 0;

    for(int books : booksArr) {
        total += books;
    }

    float average = static_cast<float>(total) / numStudents;

    std::cout << "Average books read per student: " << average << std::endl;


    return 0;
}