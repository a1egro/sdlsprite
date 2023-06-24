//
// Created by alex on 23.02.22.
//

#ifndef TANO_VECTOR2_H
#define TANO_VECTOR2_H

#include <cmath>
#include <type_traits>
#include <utility>

template<typename T = float, class = std::enable_if_t<std::is_arithmetic_v<T>>>
struct Vector2 {
    typedef T element;
    typedef T &reference;

    element x, y;

    Vector2() noexcept: Vector2(0, 0) { }

    constexpr Vector2(const element &x, const element &y) noexcept: x(x), y(y) { }

    constexpr Vector2(element &&x, element &&y) noexcept: x(x), y(y) { }

    // no explicit copy or move constructor since trivially copyable

    Vector2<element> operator+(const Vector2<element> &o) const
    {
        return std::move(Vector2<element>(x + o.x, y + o.y));
    }

    void operator+=(const Vector2<element> &o)
    {
        x += o.x;
        y += o.y;
    }

    Vector2<element> operator-(const Vector2<element> &o) const
    {
        return std::move(Vector2<element>(x - o.x, y - o.y));
    }

    void operator-=(const Vector2<element> &o)
    {
        x -= o.x;
        y -= o.y;
    }

    element operator*(const Vector2<element> &o) const
    {
        return std::move(x * o.x + y * o.y);
    }

    template<typename A, class = std::enable_if_t<std::is_arithmetic_v<A>>>
    Vector2<element> operator*(const A &scaler) const
    {
        return std::move(Vector2<element>(scaler * x, scaler * y));
    }

    template<typename A, class = std::enable_if_t<std::is_arithmetic_v<A>>>
    void operator*=(const A &scaler)
    {
        x *= scaler;
        y *= scaler;
    }

    template<typename A, class = std::enable_if_t<std::is_arithmetic_v<A>>>
    Vector2<element> operator/(const A &scaler) const
    {
        return std::move(Vector2<element>(x / scaler, y / scaler));
    }

    template<typename A, class = std::enable_if_t<std::is_arithmetic_v<A>>>
    void operator/=(const A &scaler)
    {
        x /= scaler;
        y /= scaler;
    }

    [[nodiscard]] float abs2() const
    {
        return x * x + y * y;
    }

    [[nodiscard]] float abs() const
    {
        return sqrt(abs2());
    }

    void norm()
    {
        const auto a = abs();
        x /= a;
        y /= a;
    }

    Vector2<T> normed()
    {
        auto v = Vector2(x, y);
        v.norm();
        return std::move(v);
    }

    template<typename U = float, class = std::enable_if_t<std::is_arithmetic_v<U>>>
    Vector2<U> cast() const
    {
        return {static_cast<U>(x), static_cast<U>(y)};
    }
};


#endif //TANO_VECTOR2_H
