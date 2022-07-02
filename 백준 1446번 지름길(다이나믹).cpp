#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	
	int n, d, from, to, dis;
	cin >> n >> d;
	vector<int> m(d+1, 10001);
	vector<pair<int, int>> sc[10001];
	
	for(int i=0; i<n; i++){
		cin >> from >> to >> dis;
		sc[to].push_back({from, dis});
	}
	
	m[0] = 0;
	
	for(int i=1; i<=d; i++){
		if(sc[i].size() == 0) {
			m[i] = m[i-1] + 1;
		} else{
			for(auto v : sc[i]){
				m[i] = min(m[i], min(m[i-1]+1, m[v.first] + v.second));
			}
		}
	}
	
	cout << m[d] << '\n';
	
	return 0;
}
