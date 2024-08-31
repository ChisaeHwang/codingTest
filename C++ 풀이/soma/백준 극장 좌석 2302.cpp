#include <bits/stdc++.h>
using namespace std;

int dp[41]; 

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> vip(m + 2); 
    vip[0] = 0; // ���� ����
    for(int i = 1; i <= m; i++) {
        cin >> vip[i];
    }
    vip[m + 1] = n + 1; // ���� ����

    // �⺻ ���� ����
    dp[0] = 1; 
    dp[1] = 1; 
    dp[2] = 2; 


    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int result = 1;
    
    for (int i = 0; i <= m; i++) {
        int sectionLength = vip[i + 1] - vip[i] - 1; // �� ������ ���� ���
        result *= dp[sectionLength];
    }

    cout << result << endl; 

    return 0;
}

