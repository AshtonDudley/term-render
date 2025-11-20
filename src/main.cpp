#include <iostream>
#include <cstdlib>
#include <csignal>

#include "Framebuffer.hpp"
#include "Renderer.hpp"
#include <chrono>
#include <thread>

int nScreenWidth = 64;
int nScreenHeight = 32;
char c;

volatile std::sig_atomic_t g_run = 1;

void signalHandler(int signum) {
    g_run = 0;
}

Vec3 rotateY(const Vec3& v, float a) {
    float c = std::cos(a), s = std::sin(a);
    return {
        v.x * c + v.z * s,
        v.y,
       -v.x * s + v.z * c
    };
}

Vec3 rotateX(const Vec3& v, float a) {
    float c = std::cos(a), s = std::sin(a);
    return {
        v.x,
        v.y * c - v.z * s,
        v.y * s + v.z * c
    };
}

Vec2 projectOrtho(const Vec3& v, const Vec2& origin) {
    // Simple orthographic projection
    return { origin.x + v.x, origin.y - v.y };
}

int main() {
    signal(SIGINT, signalHandler);
    std::cout << "Program running. Press Ctrl+C to interrupt." << std::endl;

    Framebuffer fb(nScreenWidth, nScreenHeight);
    Renderer render(fb);

    float cubeWidth  = 10.0f;
    float cubeHeight = 10.0f;
    float cubeDepth  = 10.0f;

    Vec3 cubeVerts[8] = {
        {-cubeWidth/2, -cubeHeight/2, -cubeDepth/2}, // 0
        { cubeWidth/2, -cubeHeight/2, -cubeDepth/2}, // 1
        { cubeWidth/2,  cubeHeight/2, -cubeDepth/2}, // 2
        {-cubeWidth/2,  cubeHeight/2, -cubeDepth/2}, // 3
        {-cubeWidth/2, -cubeHeight/2,  cubeDepth/2}, // 4
        { cubeWidth/2, -cubeHeight/2,  cubeDepth/2}, // 5
        { cubeWidth/2,  cubeHeight/2,  cubeDepth/2}, // 6
        {-cubeWidth/2,  cubeHeight/2,  cubeDepth/2}  // 7
    };

    int edges[12][2] = {
        {0,1}, {1,2}, {2,3}, {3,0}, // front face
        {4,5}, {5,6}, {6,7}, {7,4}, // back face
        {0,4}, {1,5}, {2,6}, {3,7}  // side edges
    };

    Vec2 screenOrigin{
        nScreenWidth  / 2.0f,
        nScreenHeight / 2.0f
    };

    float angleX = 0.0f;
    float angleY = 0.0f;

    fb.fill('_');
    fb.set(0, 0, '#');
    fb.set(nScreenWidth-1, nScreenHeight-1, '#');

    std::system("clear");
    std::cout << "\x1b[?25l";

    // Render loop:
    int frame = 0;
    
    while (g_run) {
        
        // Clear framebuffer
        fb.fill('_');

        // Update rotation angles
        angleX += 0.03f;
        angleY += 0.05f;

        // Rotate and project all vertices
        Vec2 projected[8];
        for (int i = 0; i < 8; ++i) {
            Vec3 r = rotateY(cubeVerts[i], angleY);
            r = rotateX(r, angleX);
            projected[i] = projectOrtho(r, screenOrigin);
        }

        // Draw cube edges
        for (auto & e : edges) {
            Vec2 p0 = projected[e[0]];
            Vec2 p1 = projected[e[1]];
            render.drawLine(p0, p1, 'x');
        }

        // Move cursor to top-left and render framebuffer
        std::cout << "\x1b[H";      // cursor home
        fb.render(std::cout);       // use Framebuffer's render

        frame++;
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
    std::cout << "\x1b[?25h\n";
    return 0;
}

/*

- [ ] Render a 64x64 viewport
- [ ] Create a cube object and slowly rotate

*/

