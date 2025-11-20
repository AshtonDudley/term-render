#pragma once

#include <ostream>
#include <cmath>

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

class Vec3 {
public:
    float x;
    float y;
    float z;

    Vec3() : x(0.0f), y(0.0f), z(0.f) {}
    Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
};


inline std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    os << "(" << v.x << "," << v.y << ")";
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    os << "(" << v.x << "," << "v.y" << "," << v.z << ")";
    return os;
}

inline Vec2 rotate2D(const Vec2& p, float angleRad) {
    float c = std::cos(angleRad);
    float s = std::sin(angleRad);
    return { p.x * c - p.y * s,
             p.x * s + p.y * c };
}

