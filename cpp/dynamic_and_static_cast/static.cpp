#include <iostream>

int main() {
    // Example 1: Converting int to double
    int i = 10;
    double d = static_cast<double>(i);
    std::cout << "Converted double value: " << d << std::endl;

    // Example 2: Converting pointers
    int* pInt = &i;
    void* pVoid = static_cast<void*>(pInt);

    // Example 3: Converting from void pointer back to int pointer
    int* pIntAgain = static_cast<int*>(pVoid);

    // Example 4: Converting enum class to underlying type
    enum class Color { RED, GREEN, BLUE };
    int colorValue = static_cast<int>(Color::RED);

}