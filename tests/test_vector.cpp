#include <iostream>
#include <ostream>
#include "Math.hpp"
#include "Renderer.hpp"
#include "Framebuffer.hpp"

int gWidth = 32;
int gHeight = 16;

int testDrawPixel() {
    Framebuffer fb(16, 8, '#');
    Renderer render(fb);
    
    std::cout << "Pixel Test:" << std::endl << std::endl; 
    render.drawPixel(1, 1,'*');
    // render.printFrame(std::cout);

    return 0;
} 


int testDrawLine() {
    Framebuffer fb(gWidth, gHeight, '#');
    Renderer render(fb);
   
    std::ostream &os = std::cout;

    std::cout << "Line Test:" << std::endl << std::endl; 
    Vec2 A{1.0f, 1.0f};
    Vec2 B{4.0f, 5.0f};
    
    Vec2 Origin{0.0f, 0.0f};
    
    Vec2 TL = Origin;
    Vec2 BR{(float)gWidth-1, (float)gHeight-1};
    Vec2 BL{0, (float)gHeight-1};
    Vec2 TR{(float)gWidth-1, 0}; 

    render.drawLine(A, B,'*');

    render.drawLine(TL, BL,'X');
    render.drawLine(BL, BR,'X');
    render.drawLine(BR, TR,'X');
    render.drawLine(TR, TL,'X');

    render.printFrame(os);

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

int testVec3() {
    
    Vec3 A{0.0f, 0.0f, 0.0f};
    Vec3 B{0.0f, 0.0f, 0.0f};

    std::cout << A << std::endl;
    std::cout << B << std::endl;
    
    return 0;
}

int testDrawCube() {
    Framebuffer fb(gWidth, gHeight, '#');
    Renderer render(fb);
   
    std::ostream &os = std::cout;
    os << "Drawing Cube Test:" << std::endl << std::endl;

    float cubeHeight = 6;
    float cubeWidth = 12;
    Vec2  cubeOrigin( 5.0f, 5.0f);

    float cubeLenth = 4;


    // Most basic square
    Vec2 A{0,0};
    Vec2 B{cubeWidth,0};
    Vec2 C{0,cubeHeight};
    Vec2 D{cubeWidth, cubeHeight};

    Vec2 E{5.0f, -3.0f};


    A = A + cubeOrigin;
    B = B + cubeOrigin;
    C = C + cubeOrigin; 
    D = D + cubeOrigin;

    render.drawSquare2D(A, B, C, D, 'x');
    render.drawSquare2D(A, B, A+E, B+E, 'x');
    render.drawSquare2D(B, D, B+E, D+E, 'x'); 

    //render.drawTriangle2D(A, B, E, 'x');

    render.printFrame(os);

    return 0;
}

int testDrawTriangle() {
    Framebuffer fb(gWidth, gHeight, '#');
    Renderer render(fb);
   
    std::ostream &os = std::cout;
    os << "Drawing Tiangle Test:" << std::endl << std::endl;
    
    float width = 16.0f;
    float height = 8.0f;

    Vec2 triangleOrigin{5.0f, 3.0f};

    Vec2 A = {0, 0};
    Vec2 B = {width, 0};
    Vec2 C = {width/2, height};

    A = A + triangleOrigin;
    B = B + triangleOrigin;
    C = C + triangleOrigin;

    render.drawTriangle2D(A, B, C, 'X');
   
    render.printFrame(os);
    return 0;
}


int main() {
    int r = test2DVectorMath();
    std::cout << "test2DVectorMath" << ": " << (r == 0 ? "PASS" : "FAIL") << "\n";

    r = testVec3();
    std::cout << "testVec3" << ": " << (r == 0 ? "PASS" : "FAIL") << "\n";   

    r = testDrawLine();
    std::cout << "testDrawLine" << ": " << (r == 0 ? "PASS" : "FAIL") << "\n";   

    r = testDrawPixel();
    std::cout << "testDrawPixel" << ": " << (r == 0 ? "PASS" : "FAIL") << "\n";   
   
    r = testDrawCube();
    std::cout << "testDrawCube" << ": " << (r == 0 ? "PASS" : "FAIL") << "\n";   
    
    r = testDrawTriangle();
    std::cout << "testDrawTriangle" << ": " << (r == 0 ? "PASS" : "FAIL") << "\n";   
    
    return 0; 
}
