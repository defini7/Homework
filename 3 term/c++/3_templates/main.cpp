#include <iostream>
#include <string>
#include <format>
#include <type_traits>

template <class T>
class Vec2D
{
    static_assert(std::is_arithmetic_v<T>, "T in vec2d<T> is not an arithmetic type");

public:
    Vec2D(T x = 0, T y = 0) : x(x), y(y) {}

    T x, y;

    static T s_SomeStaticVariableWithTypeT;

};

template <class T>
T Vec2D<T>::s_SomeStaticVariableWithTypeT = 666;

namespace std
{
    string to_string(const Vec2D<int>& v)
    {
        return format("int: ({}, {})", v.x, v.y);
    }

    string to_string(const Vec2D<double>& v)
    {
        return format("double: ({}, {})", v.x, v.y);
    }

    string to_string(const Vec2D<long double>& v)
    {
        return format("long double: ({}, {})", v.x, v.y);
    }

    template <class T>
    string to_string(const Vec2D<T>& v)
    {
        return format("({}, {})", v.x, v.y);
    }
}

int main()
{
    using namespace std;

    Vec2D<int> v1(1, 2);
    cout << to_string(v1) << endl;

    cout << Vec2D<int>::s_SomeStaticVariableWithTypeT << endl;

    Vec2D<double> v2(3, 4);
    cout << to_string(v2) << endl;

    Vec2D<long double> v3(5.5, 6.6);
    cout << to_string(v3) << endl;
}
