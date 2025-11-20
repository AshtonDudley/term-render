#pragma once

#include "Framebuffer.hpp"
#include "Math.hpp"

// void renderLoop(Framebuffer& fb);

class Renderer {
public:
    explicit Renderer(Framebuffer& fb); 

    void drawPixel(int x, int y, char ch);
    void drawLine(Vec2 a, Vec2 b, char ch);
 
    void drawTriangle2D(Vec2 A, Vec2 B, Vec2 C, char ch);
    void drawSquare2D(Vec2 A, Vec2 B, Vec2 C, Vec2 D, char ch);

    void drawTrangle3D(Vec3 A, Vec3 B, Vec3 C, char ch);

    void renderFrame();
    void printFrame(std::ostream& os);

private:
    Framebuffer& framebuffer;
};
