#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
	
	cin >> t;
	
	while(t--) {
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		int n, m;
		
		cin >> n >> m;
	
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			pq.push({b, a});
		}
		
		bool book[1001] = {false};
		int cnt = 0;
		
	    while(!pq.empty()){
			int b = pq.top().first;
			int a = pq.top().second;
			pq.pop();
			
			int i;
			for (i = a; i <= b; i++){
				if(!book[i]) {
					book[i] = true;
					cnt++;
					break;
				}
			}
		}
		
		cout << cnt << '\n';
	
	}
	
	return 0;
}

