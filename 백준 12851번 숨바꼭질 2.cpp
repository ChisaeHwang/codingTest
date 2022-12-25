#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000; 
int visited[MAX+4];
long long cnt[MAX+4];
int main() {
    int n, m;
    cin >> n >> m;
    
    if(n == m){
        puts("0"); 
		puts("1");
        return 0; 
    } 
    
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : {now-1, now+1, now*2}) {
            if (0 <= next && next <= MAX) { 
                if (!visited[next]) { // �湮���� �ʾҰ�, ������ �ִܽð� Ž�� 
                    q.push(next); 
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now]; // ���� ����� ������ �� �����־�� �� 
                    // next�� ���� now + 1�� ���� ���� ��쿣 �ִܽð��� 
                } else if (visited[next] == visited[now] + 1) { // min���� ������ �� ���� 
                    cnt[next] += cnt[now]; // �̰Ͷ��� �������� 
                }
            }
        }
    }
    
    cout << visited[m] - 1 << '\n';
    cout << cnt[m] << '\n';
    
    return 0;
}
