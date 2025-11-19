#pragma once

#include <ostream>

class Vec2 {
public:
    float x;
    float y;

    Vec2() : x(0.0f), y(0.0f) {}
    Vec2(float x_, float y_) : x(x_), y(y_) {}

    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator*(float s) const {
        return Vec2(x * s, y * s);
    }

    // Scalar * Vec2 as free function
    friend Vec2 operator*(float s, const Vec2& v) {
        return Vec2(v.x * s, v.y * s);
    }
};

inline std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    os << "(" << v.x << "," << v.y << ")";
    return os;
}
