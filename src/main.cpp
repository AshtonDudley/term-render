#include <iostream>
#include <cstdlib>
#include <csignal>

#include "Framebuffer.hpp"
#include "Renderer.hpp"

int nScreenWidth = 32;
int nScreenHeight = 16;
char c;

volatile std::sig_atomic_t g_run = 1;

void signalHandler(int signum) {
    g_run = 0;
}


int main() {
    signal(SIGINT, signalHandler);
    std::cout << "Program running. Press Ctrl+C to interrupt." << std::endl;

    Framebuffer fb(nScreenWidth, nScreenHeight);

    fb.fill('_');
    fb.set(0, 0, '#');
    fb.set(nScreenWidth-1, nScreenHeight-1, '#');

    std::system("clear");
    std::cout << "\x1b[?25l";

    // Render loop:
    int frame = 0;
    
    while (g_run) {

        int index = frame % (fb.getWidth() * fb.getHeight());
        int x = index % fb.getWidth();
        int y = index / fb.getWidth();

        fb.setIndex(index, '#');

        renderLoop(fb);
        
        fb.setIndex(index, ' ');
        
        frame++;
    }
    std::cout << "\x1b[?25h\n";
    return 0;
}

/*

- [ ] Render a 64x64 viewport
- [ ] Create a cube object and slowly rotate

*/

