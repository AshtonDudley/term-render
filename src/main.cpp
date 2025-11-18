#include <iostream>
#include <vector>

int nScreenWidth = 32;
int nScreenHeight = 16;
char c;

class Framebuffer {
    public:
        Framebuffer(int w, int h, char fill = ' ')
            : width(w), height(h), buffer(w * h, fill) {}

    void render() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                std::cout << "";
            }
            std::cout << std::endl;
        }

    }

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

int main() {
    std::cout << "Hello World" << std::endl;
  
    Framebuffer fb(nScreenWidth, nScreenHeight);
    fb.render();

    return 0;
}

/*

- [ ] Render a 64x64 viewport
- [ ] Create a cube object and slowly rotate

*/

