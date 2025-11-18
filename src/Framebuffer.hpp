#pragma once

#include <vector>
#include <iosfwd> 

class Framebuffer {
public:
    Framebuffer(int w, int h, char fill = ' ');

    void render(std::ostream& os) const;

    void set(int x, int y, char ch);
    void setIndex(int index, char ch);

    char get(int x, int y) const;

    void fill(char ch);

    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    int width;
    int height;
    std::vector<char> buffer;
};

