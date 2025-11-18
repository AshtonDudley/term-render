#include "Framebuffer.hpp"

#include <ostream>
#include <algorithm>

Framebuffer::Framebuffer(int w, int h, char fill)
    : width(w), height(h), buffer(w * h, fill) {}

void Framebuffer::render(std::ostream& os) const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            os << buffer[y * width + x];
        }
        os << '\n';
    }
}

void Framebuffer::set(int x, int y, char ch) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return;
    }
    buffer[y * width + x] = ch;
}

void Framebuffer::setIndex(int index, char ch) {
    if (buffer.empty()) {
        return;
    }
    buffer[index % (width * height)] = ch;
}

char Framebuffer::get(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return ' ';
    }
    return buffer[y * width + x];
}

void Framebuffer::fill(char ch) {
    std::fill(buffer.begin(), buffer.end(), ch);
}

