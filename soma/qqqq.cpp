#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> visited;
vector<vector<pair<int, int>>> pre;
vector<pair<int, int>> path;
vector<pair<int, int>> p;
bool flag = true;
const int INF = 1e9;
int n, m;

void prevF(int sx, int sy, int ex, int ey, int num) {
    int cx = ex;
    int cy = ey;

    while (true) {
        path.push_back({cx, cy});
        arr[cx][cy] = num;
        if (cx == sx && cy == sy) {
            break;
        }
        pair<int, int> prev = pre[cx][cy];
        if (prev.first < 0 || prev.first >= n + 1 || prev.second < 0 || prev.second >= m + 1) {
            flag = false;
            return;
        }
        cx = prev.first;
        cy = prev.second;
    }

    reverse(path.begin(), path.end());
}


void dij(int x, int y, int endx, int endy) {
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> pq;
                   
    pq.push({0, {x, y}});
    visited[x][y] = 0;

    while (!pq.empty()) {
        int distance = pq.top().first;
        pair<int, int> current = pq.top().second;
        pq.pop();

        int cx = current.first;
        int cy = current.second;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= n + 1 || ny < 0 || ny >= m + 1) continue;
            if (arr[nx][ny] == 1) continue;
            
            if(arr[nx][ny] == 0) {
                if (visited[nx][ny] > distance + 1) {
	                visited[nx][ny] = distance + 1;
	                pre[nx][ny] = {cx, cy};
	                pq.push({visited[nx][ny], {nx, ny}});
	            }	
			}
        }
    }
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    cin >> m >> n;

    arr.resize(n + 1, vector<int>(m + 1, 0));
    visited.resize(n + 1, vector<int>(m + 1, INF));
    pre.resize(n + 1, vector<pair<int, int>>(m + 1, {-1, -1}));

    for (int i = 0; i < 4; i++) {
		int x, y;
	    cin >> x >> y;
	    p.push_back({x, y});
	    arr[y][x] = 3;
  	}

    // 첫 번째 경로 계산
    dij(p[0].second, p[0].first, p[1].second, p[1].first);
    prevF(p[0].second, p[0].first, p[1].second, p[1].first, 1);

    int firstPathLength = visited[p[1].second][p[1].first];

    for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	
	    cout << "첫 번째 경로: ";
    for (auto& coord : path) {
        cout << "(" << coord.first << ", " << coord.second << ") ";
    }
    cout << '\n';


    // path 벡터 초기화
    path.clear();

    // visited와 pre 배열 재설정
    fill(visited.begin(), visited.end(), vector<int>(m + 1, INF));
    fill(pre.begin(), pre.end(), vector<pair<int, int>>(m + 1, {-1, -1}));

    // 두 번째 경로 계산
    dij(p[2].second, p[2].first, p[3].second, p[3].first);
    prevF(p[2].second, p[2].first, p[3].second, p[3].first, 2);

    int secondPathLength = visited[p[3].second][p[3].first];
   
   
    cout << "두 번째 경로: ";
    for (auto& coord : path) {
        cout << "(" << coord.first << ", " << coord.second << ") ";
    }
    cout << '\n';
    
    for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}


    // 불가능한 경우 체크
    if (!flag) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << firstPathLength + secondPathLength << '\n';
    }

    return 0;
}

