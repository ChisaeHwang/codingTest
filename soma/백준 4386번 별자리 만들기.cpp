#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int n;
// �Ǽ��� �� ������ double ��� 
pair<double, double> star[101]; // �� ��ǥ ���� �迭 
bool visited[101]; // �湮 ���� üũ 
vector<double> minCnt(101, INF); // ��纰 ���Ѵ�� ���� 

double getDist(pair<double, double> a, pair<double, double> b) {
    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt(x*x + y*y); 
}

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> star[i].first >> star[i].second;
	}
	
	minCnt[0] = 0;
	double ret = 0;
	 
	 
	// prim �˰��� 
	for (int i = 0; i < n; i++) {
		int now = -1;
		double minDist = INF;
		
		for (int j = 0; j < n; j++) {
			// �湮���� ���߿� �ּ� ��� ã�� 
			if (!visited[j] && minDist > minCnt[j]) {  
				minDist = minCnt[j];
				now = j;
			}
		}
		
		visited[now] = true;
		ret += minDist;
		 
		for (int j = 0; j < n; j++) {
			double cost = getDist(star[now], star[j]);
			if (!visited[j] && cost < minCnt[j]) {
				minCnt[j] = cost;
			}
		}
	}
	
	
	cout.precision(2); // �Ҽ��� ���� ��° �ڸ����� ��� ���� 
    cout << fixed << ret << '\n';
	
	
	return 0;
}
