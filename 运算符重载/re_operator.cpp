/*
*   运算符重载
*/

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Point
{
private:
    double x{}, y{};

public:
    Point(double x, double y) : x{x}, y{y} {}
    Point operator+(const Point &other)
    {
        return Point(x + other.x, y + other.y);
    }

    friend void print(const Point &p);
};

void print(const Point &p)
{
    cout << p.x << ", " << p.y;
    cout << endl;
}

int main()
{

    Point P{2, 3}, Q{4, 5};
    
    // P + Q实际上是P.operator＋(Q)的简写形式。即通过对象Р调用Point的成员函数operator+()并将参数Q传递给这个函数。
    print(P + Q); // 输出6, 8
    
    system("pause");
}