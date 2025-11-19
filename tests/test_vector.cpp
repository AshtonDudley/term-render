#include <iostream>
#include "Math.hpp"
#include "Renderer.hpp"
#include "Framebuffer.hpp"


int testDrawPixel() {
    Framebuffer fb(32, 16, '#');
    Renderer render(fb);
    
    std::cout << "Pixel Test:" << std::endl << std::endl; 
    renderLoop(fb);
    render.drawPixel(1, 1,'*');

    return 0;
} 


int testDrawLine() {
    Framebuffer fb(32, 16, '#');
    Renderer render(fb);
    
    std::cout << "Line Test:" << std::endl << std::endl; 
    renderLoop(fb);
    Vec2 A{1.0f, 1.0f};
    Vec2 B{4.0f, 4.0f};
    render.drawLine(A, B,'*');

    return 0;
} 

int test2DVectorMath() {

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


int main() {
    int r = test2DVectorMath();
    std::cout << "test2DVectorMath" << ": " << (r == 0 ? "PASS" : "FAIL") << "\n";

    r = testDrawLine();
    std::cout << "testDrawLine" << ": " << (r == 0 ? "PASS" : "FAIL") << "\n";   

    r = testDrawPixel();
    std::cout << "testDrawPixel" << ": " << (r == 0 ? "PASS" : "FAIL") << "\n";   
    
    return 0;
}
