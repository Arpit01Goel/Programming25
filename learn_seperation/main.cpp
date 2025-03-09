#include <iostream>
#include "Calculator.h"

int main() {
    Calculator calc;
    int result = calc.add(3, 4);
    std::cout << "The result is: " << result << std::endl;
    return 0;
}