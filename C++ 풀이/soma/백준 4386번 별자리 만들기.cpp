#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int n;
// 실수가 들어간 문제라 double 사용 
pair<double, double> star[101]; // 별 좌표 저장 배열 
bool visited[101]; // 방문 여부 체크 
vector<double> minCnt(101, INF); // 모든별 무한대로 설정 

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
	 
	 
	// prim 알고리즘 
	for (int i = 0; i < n; i++) {
		int now = -1;
		double minDist = INF;
		
		for (int j = 0; j < n; j++) {
			// 방문안한 별중에 최소 비용 찾기 
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
	
	
	cout.precision(2); // 소수점 이하 둘째 자리까지 출력 설정 
    cout << fixed << ret << '\n';
	
	
	return 0;
}
