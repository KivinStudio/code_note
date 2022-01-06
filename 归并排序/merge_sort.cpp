#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    //�ݹ���ֹ���
    if (l >= r)
        return;

    //��һ�����ֳ�������
    int mid = l + r >> 1;

    //�ڶ������ݹ鴦��������
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    //��������(2)·�鲢��˫ָ��
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }

    //���Ĳ����ϲ�δ�鲢�ĵ�Ԫ��
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    //���岽����������
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
}