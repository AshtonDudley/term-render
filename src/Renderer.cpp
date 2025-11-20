#include "Renderer.hpp"
#include "Framebuffer.hpp"

#include <chrono>
#include <thread>
#include <iostream>

Renderer::Renderer(Framebuffer& fb) 
    : framebuffer(fb) {}


void Renderer::renderFrame() {
    std::cout << "\x1b[H"; // move cursor 
    framebuffer.render(std::cout);
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
}

void Renderer::printFrame(std::ostream& os) {
    framebuffer.render(os);
}

void Renderer::drawPixel(int x, int y, char ch) {
    framebuffer.set(x, y, ch);

    return;
}

void Renderer::drawTriangle2D(Vec2 A, Vec2 B, Vec2 C, char ch) {
    drawLine(A, B, ch);
    drawLine(A, C, ch);
    drawLine(B, C, ch);
    return;
}


// A: top left, B: top right, C: bottom left, D: bottom right
void Renderer::drawSquare2D(Vec2 A, Vec2 B, Vec2 C, Vec2 D, char ch) {
   drawLine(A, B, ch);
   drawLine(B, D, ch);
   drawLine(D, C, ch);
   drawLine(C, A, ch);
}


/*
    SIMPLE METHOD:
    where, x2 > x1 
    dx = x2 − x1
    dy = y2 − y1
    m = dy/dx
    for x from x1 to x2 do
        y = m × (x − x1) + y1
        plot(x, y)
 */

void Renderer::drawLine(Vec2 a, Vec2 b, char ch) {
    if (a.x > b.x) std::swap(a, b);

    float dx = b.x - a.x;
    float dy = b.y - a.y; 
    
    if (dx == 0) {   // vertical line
        if (a.y > b.y) std::swap(a, b);
        for (int y = a.y; y <= b.y; y++)
            framebuffer.set(a.x, y, ch);
        return;
    }

    float m = dy / dx;

    for (int x = (int)a.x; x <= (int)b.x; x++) {
        float y = m * (x - a.x) + a.y;
        framebuffer.set(x, y, ch);
    }
    return;
}

