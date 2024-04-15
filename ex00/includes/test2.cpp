#include <iostream>
#include <type_traits>

// Generic function to convert between numeric types
template <typename From, typename To>
To convert(From value) {
    static_assert(std::is_arithmetic<From>::value && std::is_arithmetic<To>::value,
                  "Both 'From' and 'To' types must be numeric.");

    return static_cast<To>(value);
}

int main() {
    double myDouble = 48.8;
    int myInt = convert<double, int>(myDouble);

    std::cout << "Converted int: " << myInt << std::endl;

    // You can use the 'convert' function for other conversions as well
    float myFloat = convert<int, float>(myDouble);
    char myChar = convert<int, char>(myDouble);

    std::cout << "Converted float: " << myFloat << std::endl;
    std::cout << "Converted char: " << myChar << std::endl;

    return 0;
}