// ���� DP ����ģ��
// ���е�����dp���⣬��һά����ö�����䳤�ȣ�һ�� len = 1 ������ʼ����ö�ٴ� len = 2 ��ʼ���ڶ�άö����� i ���Ҷ˵� j �Զ���ã�j = i + len - 1��
#include <iostream>

using namespace std;

const int N = 307;

int a[N], s[N];
int f[N][N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] += s[i - 1] + a[i];
    }

    // ���� DP ö����·������+��˵� 
    for (int len = 1; len < n; len ++) { // len��ʾi��j���±�Ĳ�ֵ
        for (int i = 1; i + len <= n; i ++) {
            int j = i + len; // �Զ��õ��Ҷ˵�
            f[i][j] = 1e8;
            for (int k = i; k <= j - 1; k ++) { // ��������k + 1 <= j
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

    cout << f[1][n] << endl;


    return 0;
}
