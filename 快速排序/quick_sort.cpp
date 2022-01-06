/*
1. 确定分界点：x = q[l]、q[(l + r) / 2]、q[r]
2. 调整区间：使得左边区间所有的数 <= x，右边区间所有的数 >= x
3. 递归处理左右两端，左右两边分别排好序后，即最终结果是有序的
*/

#include <iostream>

using namespace std;

const int N = 1e6;
int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int x = q[(l + r) / 2], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        // 如果q[i] > x，则q[i]放到右边
        // 如果q[j] < x，则q[j]放到左边
        // 如果两个指针还没有相遇，就交换一下
        if (i < j)
            swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}   

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    
    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    
    return 0;
}