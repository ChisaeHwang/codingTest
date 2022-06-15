#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int d[1001][1001]; // 거리 배열 
int main()
{			
	int n;
	cin >> n;
	
	memset(d, -1, sizeof(d)); // -1 로 초기화 
    queue<pair<int,int>> q;
    q.push(make_pair(1,0));
	d[1][0] = 0;
	pair<int , int > pp;
	
	while(!q.empty()){
		int s, c;
		// tie : 튜플의 값알 가져와 값을 따로 분류할 때 사용하는 함수
		tie(s, c) = q.front(); // 각각 값 분배 
		q.pop();
		// 0 이상 :  방문함 / -1 : 방문 안함 
		if(d[s][s] == -1){
			d[s][s] = d[s][c] + 1;
			pp = {s, s};
			q.push(pp);
		}
		if(s+c <= n && d[s+c][c] == -1){
			d[s+c][c] = d[s][c] + 1;
			q.push(make_pair(s+c, c));
		}
		if(s-1 >= 0 && d[s-1][c] == -1){
			d[s-1][c] = d[s][c] + 1;
			q.push(make_pair(s-1, c));
		}
	}
	
	int ans = -1;
    for (int i=0; i<=n; i++) {
        if (d[n][i] != -1) {
            if (ans == -1 || ans > d[n][i]) {
                ans = d[n][i];
            }
        }
    }
    cout << ans << '\n';
    return 0;
	
}
