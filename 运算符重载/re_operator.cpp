/*
*   ���������
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
    
    // P + Qʵ������P.operator��(Q)�ļ�д��ʽ����ͨ�����󧲵���Point�ĳ�Ա����operator+()��������Q���ݸ����������
    print(P + Q); // ���6, 8
    
    system("pause");
}