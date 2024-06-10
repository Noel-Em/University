#include <iostream>

void fibonacci(int limit = 10, int value1 = 0, int value2 = 1) {
    
    if(!value1 && !value2) {
        value1 = 1;
    }

    std::cout << (value1 + value2) << std::endl;

    if (value1 < value2) {
        value1 = value1 + value2;
    }
    else {
        value2 = value1 + value2;
    }

    if( value1 + value2 < limit)
        fibonacci(limit, value1, value2);
}

int main() {
    fibonacci(20, 0, 0);
}