#include <bits/stdc++.h>

using namespace std;

// �迭���� �ʹ� Ŀ�� ī���� �迭�� ���� 
int n, l, a, b, ret, idx, cnt;

int main() {
	
	cin >> n >> l;
	
	vector<pair<int, int>> v(n); 
	
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (v[i].second <= idx) continue;
		
		if (idx < v[i].first) { // ���� ��ġ�� �������� start ���� ���� ��쿡 (�� ��ġ�� ���) 
			// ��ⷯ ���� -> true�� ������ 1�̶� �� -> �� �����ϳ� �� �־���� 
			cnt = (v[i].second - v[i].first) / l + ((v[i].second - v[i].first) % l ? 1 : 0); 
			idx = v[i].first + cnt * l; // �������� start ��ġ + ���� �� * ���� ���� 
		} else { // ���� ��ġ�� �������� start���� ū ��쿡 (��ġ�� ���) 
			cnt = (v[i].second - idx) / l + ((v[i].second - idx) % l ? 1 : 0); 
			idx += + cnt * l;
		}
		
		ret += cnt;
	}
	
	cout << ret << '\n';

	
	return 0;
} 
