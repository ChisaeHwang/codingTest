#include <bits/stdc++.h>
#define MAX 201
#define INF 1e9

using namespace std;

int n, m;
double graph[MAX][MAX];
double fdist[MAX][MAX]; 

int main() {
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		fill(graph[i], graph[i] + n + 1, INF);
		fill(fdist[i], fdist[i] + n + 1, -1);
		graph[i][i] = 0; // 본인은 가중치 X 
	}
	
	for(int i = 1; i <= m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		
		if(cost == INF || cost < graph[from][to]) {
			graph[from][to] = cost;
			graph[to][from] = cost;	
		}
		
		if(cost == -1 || cost > fdist[from][to]) {
			fdist[from][to] = cost;
			fdist[to][from] = cost;
		}
		
	}
	
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				graph[i][j] = min (graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	double short_time = INF, long_time, spent_time, remain_len;
  	int edge_len;
  	
  	for(int start = 1; start <= n; start++) {
  		long_time = 0; // 각 정점 하나씩 돌면서 최단거리 측정 
  		
  		for(int from = 1; from <= n; from++) {
  			for(int to = 1; to <= n; to++) {
  				edge_len = fdist[from][to];
  				
  				if (edge_len != -1) { // 간선 check 
  					remain_len = edge_len - (graph[start][to] - graph[start][from]);
  					
  					if(remain_len > 0) { // remain_len이 있을 경우 
  						spent_time = (remain_len/2) + graph[start][to]; // 남은 시간 
  						long_time = max(long_time, spent_time); // 가장 긴 시간 체크 
					  }
  					
				  }
			  }
		  }
		  
		  short_time = min(short_time, long_time);
	  }
  	
  	printf("%.1f\n", short_time);
	
	return 0;
}
