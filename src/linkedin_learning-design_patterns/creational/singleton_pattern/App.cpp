#include <iostream>
class Leader {
private:
    static Leader *instance;
    Leader () {
        std::cout << "New leader elected\n";
    }

public:
    static Leader *getInstance() {
        if(instance) {
            return instance;
        } else {
            instance = new Leader();
            return instance;
        }
    }

    void giveSpeech() {
        std::cout << "Address the public\n";
    }
};

Leader* Leader::instance = nullptr;

int main() {
    Leader::getInstance()->giveSpeech();

    Leader *elected = elected->getInstance();

    elected->giveSpeech();

    return 0;
}