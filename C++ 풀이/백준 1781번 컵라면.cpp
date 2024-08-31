#include <bits/stdc++.h>

using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end()); // ������μ� ����
	
	for (int i = 0; i < v.size(); i++) {
		ret += v[i].second; // ������μ� �Ŷ�� �� �ֱ�
		pq.push(v[i].second);
		if (pq.size() >= v[i].first + 1) { // ������� ������ �� ������ 
			ret -= pq.top(); // �������� �����̶� ������ ����� greater<int> ���� �������� 
			pq.pop();
		} 
	} 
	
	cout << ret << '\n';
	
	return 0;
}
