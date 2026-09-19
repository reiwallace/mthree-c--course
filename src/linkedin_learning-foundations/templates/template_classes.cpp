#include <iostream>

template <typename T>
class GameEntity{
    T x;
    T y;
    
public:
    GameEntity(T x, T y): x(x), y(y) {}

    void viewCoords() {
        std::cout << "X: " << x << std::endl;
        std::cout << "Y: " << y << std:: endl;
    }
};


int main() {
    GameEntity<float> ent(3.0, 0.2);
    ent.viewCoords();

    GameEntity<int> flatEnt(1, 4);
    flatEnt.viewCoords();
    return 0;
}