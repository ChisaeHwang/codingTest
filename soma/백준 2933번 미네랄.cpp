#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
int x, y, d;

vector<vector<char>> adj;
vector<pair<int, int>> airC;
vector<vector<int>> visited;
vector<int> stick;

void stickFun(int x, int th) {
  x = n - x; // 높이 조정
  if (th % 2 == 0) { // 왼쪽으로 던지는 경우
    for (int i = 0; i < m; i++) {
      if (adj[x][i] == 'x') {
        adj[x][i] = '.';
        break;
      }
    }
  } else {
    for (int i = m - 1; i >= 0; i--) {
      if (adj[x][i] == 'x') {
        adj[x][i] = '.';
        break;
      }
    }
  }
}

void bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});
  visited[x][y] = 1;

  while (q.size()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (!visited[nx][ny] && adj[nx][ny] == 'x') {
        visited[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }
}

int find_C() {
  int can = 0;

  for (int i = 0; i < n; i++) {
    if (adj[n - 1][i] == 'x' && !visited[n - 1][i]) {
      bfs(n - 1, i);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (adj[i][j] == 'x' && !visited[i][j]) {
        airC.push_back({i, j});
        can = 1;
      }
    }
  }

  return can;
}

int move(int x, int y) {
  int cnt = 0;
  for (int i = x + 1; i < n; i++) {
    if (adj[i][y] == 'x') { // 밑에가 클러스터일 경우 
      if (!visited[i][y]) {
        return INF; // 밑에 클러스터가 있음
      } else {
        return cnt;
      }
    } else {
    	cnt++;
	}
  }

  return cnt;
}

void remake() {
  int down = INF;
  for (int i = 0; i < airC.size(); i++) {
    int cnt = move(airC[i].first, airC[i].second);
    down = min(down, cnt);
  }
  if(down == INF) return;
  for(int i = 0; i < airC.size(); i++) {
    int x = airC[i].first;
    int y = airC[i].second;
    adj[x][y] = '.';
  }
  for(int i = 0; i < airC.size(); i++) {
    int x = airC[i].first;
    int y = airC[i].second;
    adj[x + down][y] = 'x';
  }
}

int main() {

  cin >> n >> m;

  adj.resize(n, vector<char>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> adj[i][j];
    }
  }

  int t;

  cin >> t;
  
  stick.resize(t);

  for (int i = 0; i < t; i++) {
    cin >> stick[i];
  }

  for(int i = 0; i < stick.size(); i++) {
    visited.clear();
   	visited.resize(n, vector<int>(m, 0)); 
    airC.clear();

    stickFun(stick[i], i);

    if (find_C()) {
      remake();
    }
    
      for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << adj[i][j];
    }
    cout << '\n';
  }
    cout << '\n';  cout << '\n';
  }


  return 0;
}
