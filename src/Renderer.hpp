#pragma once

#include "Framebuffer.hpp"
#include "Math.hpp"

void renderLoop(Framebuffer& fb);

class Renderer {
public:
    explicit Renderer(Framebuffer& fb);

    void drawPixel(int x, int y, char ch);
    void drawLine(Vec2 a, Vec2 b, char ch);

private:

};
