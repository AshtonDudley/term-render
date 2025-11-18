#pragma once

#include "Framebuffer.hpp"

void renderLoop(Framebuffer& fb);

class Renderer {
public:
    explicit Renderer(Framebuffer& fb);

    void drawPixel(int x, int y, char ch);
    void drawLine(int x, int y, char ch);
private:

};
