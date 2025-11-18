#include <iostream>
#include <vector>
#include <cstdlib>
#include <csignal>
#include <chrono>
#include <thread>

int nScreenWidth = 32;
int nScreenHeight = 16;
char c;

volatile std::sig_atomic_t g_run = 1;

class Framebuffer {
    public:
        Framebuffer(int w, int h, char fill = ' ')
            : width(w), height(h), buffer(w * h, fill) {}

    void render(std::ostream& os) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                os << buffer[y * width + x];
            }
            os << std::endl;
        }
    }

    void set(int x, int y, char ch) {
        if (x < 0 || x >= width || y < 0 || y >= height) { return; }
        buffer[y * width + x] = ch;
        return;
    }
    void setIndex(int index, char ch) {
        buffer[index % (width * height)] = ch;
    }

    char get(int x, int y) {
        if (x < 0 || x >= width || y < 0 || y >= height) { return ' '; }
        return buffer[y * width + x];
    }

    void fill(char ch) {
        std::fill(buffer.begin(), buffer.end(), ch);
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    private:
        int width;
        int height;
        std::vector<char> buffer;
};






int printBasicScreen(int screenWidth, int screenHeight) { 
    for (int i = 0; i < screenWidth; i++) {
        for (int j = 0; j < screenHeight; j++) {
            std::cout << "\u2588";
        }
        std::cout << std::endl;
    }

    return 0; 
}

void signalHandler(int signum) {
    g_run = 0;
}

void renderLoop(Framebuffer& fb) {
    std::cout << "\x1b[H"; // move cursor 
    fb.render(std::cout); 
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
    return;
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

        // fb.set(x, y, '#');
        //fb.set(x-1, y, ' ');
        
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

