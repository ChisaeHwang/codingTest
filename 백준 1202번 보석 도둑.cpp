#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a, b, k, ret, num; // type은 묵시적 변환에 의존하지 말자 

int main() {
	
	cin >> n >> k; 
	
	vector<pair<ll,ll>> v(n);
	vector<ll> vc(k); 
	
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second; 
	}
	for(int i = 0; i < k; i++) cin >> vc[i]; 
	
	sort(v.begin(), v.end()); // 무게 기반 오름차순 
	sort(vc.begin(), vc.end()); // 그냥 오름차순 
	priority_queue<ll> pq;  // 내림차순 
	
	// 각 가방에는 최대 한 개의 보석을 담을 수 있음
	// -> 가장 작은 거 보석 : 가장 작은 가방 으로 매칭 
	

	int j = 0;
	for(int i = 0; i < k; i++){
		while(j < n && v[j].first <= vc[i]) pq.push(v[j++].second);
		if(pq.size()){
			ret += pq.top(); pq.pop();
		}
	} 
	cout << ret << '\n';
	
	return 0; 
} 
