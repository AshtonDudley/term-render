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

