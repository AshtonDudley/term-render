#pragma once

#include <cmath>

// 2D Vector Functions 

struct Vec2 {
    float x{};
    float y{};

    Vec2() = default;
    Vec2(float x_, float y_) : x(x_), y(y_) {}
};

inline Vec2 operator+(const Vec2& a, const Vec2& b) {
    return {a.x + b.x, a.y + b.y};
}

inline Vec2 operator-(const Vec2& a, const Vec2& b) {
    return {a.x - b.x, a.y - b.y};
}

inline Vec2 operator*(const Vec2& v, float s) {
    return {v.x * s, v.y * s};
}

inline Vec2 operator*(float s, const Vec2& v) {
    return v * s;
}

// 3D Vector Functions

struct Vec3 {
    float x, y, z;
}


