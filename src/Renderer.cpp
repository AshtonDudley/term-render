#include "Renderer.hpp"
#include "Framebuffer.hpp"

#include <chrono>
#include <thread>
#include <iostream>

void renderLoop(Framebuffer& fb) {
    std::cout << "\x1b[H"; // move cursor 
    fb.render(std::cout); 
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
    return;
}


Renderer::Renderer(Framebuffer& fb) 
    : framebuffer(fb) {}

// line is dv_a^b
void Renderer::drawPixel(int x, int y, char ch) {
    return;
}
void Renderer::drawLine(Vec2 a, Vec2 b, char ch) {
    return;
}

