#include <iostream>
#include "Math.hpp"


int main() {
    std::cout << "Starting Vector Test" << std::endl;
    
    Vec2 A{1.0f, 2.0f};
    Vec2 B{1.0f, 2.0f};

    Vec2 C = A + B;

    std::cout << C << std::endl;

}
