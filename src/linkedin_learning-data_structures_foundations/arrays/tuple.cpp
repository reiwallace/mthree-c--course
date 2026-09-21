#include <iostream>
#include <tuple>

/**
    Calculates a square's properties from its side length
    @param side_length - Side length of the square
    @returns Tuple containing the square's area(0) and perimeter(1)
*/
std::tuple<int, int> calculateSquareProperties(int side_length) {
    int area = side_length * side_length;
    int perimeter = side_length * 4;
    return std::make_tuple(area, perimeter);
}

int main() {
    std::tuple<int, int> point(5, 2);

    int x = std::get<0>(point);
    int y = std::get<1>(point);

    auto result = calculateSquareProperties(10);
    std::cout << "Area: " << std::get<0>(result) << std::endl;
    std::cout << "Perimeter: " << std::get<1>(result) << std::endl;

    return 1;
}