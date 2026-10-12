#include <iostream>
#include <vector>

class NumberIterator {
public:
    virtual ~NumberIterator() {}
    virtual int next() = 0;
    virtual bool isFinished() = 0;
};

class ForwardsIterator: public NumberIterator {
private:
    int currentPosition;
    std::vector<int> &numbers;
public:
    ForwardsIterator(std::vector<int> &numbers): currentPosition(0), numbers(numbers) {}

    int next() override {
        return numbers.at(currentPosition++);
    }

    bool isFinished() override {
        return currentPosition >= numbers.size();
    }
};

class BackwardsIterator: public NumberIterator {
private:
    int currentPosition = 0;
    std::vector<int> &numbers;
public:
    BackwardsIterator(std::vector<int> &numbers): currentPosition(numbers.size() - 1), numbers(numbers) {}

    int next() override {
        return numbers.at(currentPosition--);
    }

    bool isFinished() override {
        return currentPosition < 0;
    }
};

class NumberCollection {
private:
    std::vector<int> numbers;

public:
    NumberCollection(const std::vector<int> &numbers): numbers(numbers) {}

    NumberIterator *getForwardsIterator() { return new ForwardsIterator(numbers); }
    NumberIterator *getBackwardsIterator() { return new BackwardsIterator(numbers); }

};

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    NumberCollection nc(nums);

    NumberIterator *fi = nc.getForwardsIterator();
    NumberIterator *bi = nc.getBackwardsIterator();

    while(!fi->isFinished()) {
        std::cout << " " << fi->next();
    }

    std::cout << "\n";
    while(!bi->isFinished()) {
        std::cout << " " << bi->next();
    }


    delete fi;
    delete bi;

    std::cout << std::endl;
    return 0;
}