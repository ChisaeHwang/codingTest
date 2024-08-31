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
                if (!visited[next]) { // 방문하지 않았고, 최초의 최단시간 탐색 
                    q.push(next); 
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now]; // 이전 경우의 수들을 다 더해주어야 함 
                    // next의 값이 now + 1의 값이 같을 경우엔 최단시간임 
                } else if (visited[next] == visited[now] + 1) { // min으로 제한을 둔 느낌 
                    cnt[next] += cnt[now]; // 이것또한 마찬가지 
                }
            }
        }
    }
    
    cout << visited[m] - 1 << '\n';
    cout << cnt[m] << '\n';
    
    return 0;
}
