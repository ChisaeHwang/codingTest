#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a, b, k, ret, num; // type�� ������ ��ȯ�� �������� ���� 

int main() {
	
	cin >> n >> k; 
	
	vector<pair<ll,ll>> v(n);
	vector<ll> vc(k); 
	
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second; 
	}
	for(int i = 0; i < k; i++) cin >> vc[i]; 
	
	sort(v.begin(), v.end()); // ���� ��� �������� 
	sort(vc.begin(), vc.end()); // �׳� �������� 
	priority_queue<ll> pq;  // �������� 
	
	// �� ���濡�� �ִ� �� ���� ������ ���� �� ����
	// -> ���� ���� �� ���� : ���� ���� ���� ���� ��Ī 
	

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
