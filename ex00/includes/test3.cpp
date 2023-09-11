#include <iostream>
#include <sstream>
#include <string>

bool isDouble(const std::string& str) {
    std::istringstream iss(str);
    double testValue;

    // Attempt to read a double from the string
    if (iss >> testValue) {
        // Check if there are no trailing characters after the double
        char remaining;
        if (iss >> remaining) {
            return false; // If there are remaining characters, it's not a valid double
        }
        return true; // Successfully read a double
    }

    return false; // Couldn't read a double from the string
}

int main() {
    std::string str1 = "  3   ";
    std::string str2 = "abc";
    std::string str3 = "42.5  ";

    if (isDouble(str1)) {
        std::cout << str1 << " is a valid double." << std::endl;
    } else {
        std::cout << str1 << " is not a valid double." << std::endl;
    }

    if (isDouble(str2)) {
        std::cout << str2 << " is a valid double." << std::endl;
    } else {
        std::cout << str2 << " is not a valid double." << std::endl;
    }

    if (isDouble(str3)) {
        std::cout << str3 << " is a valid double." << std::endl;
    } else {
        std::cout << str3 << " is not a valid double." << std::endl;
    }

    return 0;
}
