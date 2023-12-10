#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char arr[105][105];
int n, m;

vector<vector<int>> dij(int sy, int sx) {
    priority_queue<tuple<int, int, int>, 
          vector<tuple<int, int, int>>, 
              greater<tuple<int, int, int>>> pq;

    vector<vector<int>> Tarr(n + 2, vector<int>(m + 2, INT_MAX));

    pq.push(make_tuple(0, sy, sx));

    while(!pq.empty()) {
        tuple<int, int, int> topElement = pq.top();
        pq.pop();
        
        int cost = get<0>(topElement);
        int y = get<1>(topElement);
        int x = get<2>(topElement);

        if(cost >= Tarr[y][x]) continue;

        Tarr[y][x] = cost;

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx >= 0 && nx <= m + 1 && ny >= 0 && ny <= n + 1 && arr[ny][nx] != '*') {
                int newCost = cost + (arr[ny][nx] == '#' ? 1 : 0);
                pq.push(make_tuple(newCost, ny, nx));
            }
        }
    }

    return Tarr;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        vector<pair<int, int>> prisoner;

   		for(int i = 0; i <= n + 1; i++) {
            for(int j = 0; j <= m + 1; j++) {
                arr[i][j] = '.';
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> arr[i][j];
                if(arr[i][j] == '$') {
                    prisoner.push_back({i, j});
                }
            }
        }
        
        vector<vector<int>> d1 = dij(0, 0);
        vector<vector<int>> d2 = dij(prisoner[0].first, prisoner[0].second);
        vector<vector<int>> d3 = dij(prisoner[1].first, prisoner[1].second);

        int ans = INT_MAX;
        

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(arr[i][j] == '*') continue;
                int temp = d1[i][j] + d2[i][j] + d3[i][j];
                if(arr[i][j] == '#') temp -= 2;
                ans = min(ans, temp);
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}

