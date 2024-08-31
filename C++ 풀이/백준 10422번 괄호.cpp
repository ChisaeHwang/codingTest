#include <iostream>
#include <cstring>
using namespace std;
long long d[5001]; //���ڿ� ���̰� i �϶� ����
long long mod = 1000000007LL;
long long go(int L) {
    if (L == 0) return 1; // �� ���ڿ�
    else if (d[L] >= 0) return d[L]; // 0���� ó���ϱ� ����
    d[L] = 0;
    for (int i = 2; i <= L; i+= 2) {
        d[L] += (go(i - 2) * go(L - i));
        d[L] %= mod;
    }
    return d[L];
}
int main()
{
    memset(d, -1, sizeof(d));
    int t; scanf("%d", &t);
    while (t--) {
        int L; scanf("%d", &L);
        if (L % 2 == 1) { //Ȧ���� ��?
            printf("0\n");
        }
        else {
            printf("%lld\n", go(L));
        }
    }
    return 0;
}
