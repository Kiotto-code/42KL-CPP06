#include <iostream>
#include <string>

class CustomConverter {
public:
    CustomConverter(double value) : value_(value) {}

    int toInt() const {
        // Implement your custom conversion logic to int here
        return static_cast<int>(value_);
    }

    float toFloat() const {
        // Implement your custom conversion logic to float here
        return static_cast<float>(value_);
    }

    char toChar() const {
        // Implement your custom conversion logic to char here
        return static_cast<char>(static_cast<int>(value_));
    }

private:
    double value_;
};

int main() {
    double myDouble = 42;
    float testFloat = 42.0f;
    std::cout << testFloat << std::endl;
    CustomConverter converter(myDouble);

    int myInt = converter.toInt();
    float myFloat = converter.toFloat();
    char myChar = converter.toChar();

    std::cout << "Converted int: " << myInt << std::endl;
    std::cout << "Converted float: " << myFloat << std::endl;
    std::cout << "Converted char: " << myChar << std::endl;

    return 0;
}
