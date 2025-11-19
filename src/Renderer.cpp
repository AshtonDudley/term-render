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
    float dx = b.x - a.x;
    float dy = b.y - a.y; 
    float m = dy / dx;

    for (int x = 0; x <= (b.x - a.x); x++) {
        float y = (m * (x - a.x)) + a.y;
        framebuffer.set(x, y, ch);
    }
    

    return;
}

