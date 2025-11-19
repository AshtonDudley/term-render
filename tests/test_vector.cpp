#include <iostream>
#include "Math.hpp"


int main() {
    std::cout << "Starting Vector Test" << std::endl;
    
    Vec2 A{1.0f, 2.0f};
    Vec2 B{1.0f, 2.0f};

    Vec2 C = A + B;
    Vec2 D = A - B;
    Vec2 E = 2 * A;
    Vec2 F = A * 2;

    std::cout << "A: " << A << std::endl;
    std::cout << "B: " << B << std::endl;

    std::cout << "A + B: " << C << std::endl;
    std::cout << "A - B: " << D << std::endl;
    std::cout << "2 * A: " << E << std::endl;
    std::cout << "A * 2: " << F << std::endl;

    return 0;
}
