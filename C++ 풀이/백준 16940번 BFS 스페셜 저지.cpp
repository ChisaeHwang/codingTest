#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a[100000];
bool check[100000];

int main(){
	
	int n;
	cin >> n;
	for(int i=0; i<n-1; i++){
		int u, v;
		cin >> u >> v;
		u -= 1; v -= 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	vector<int> b(n);
    vector<int> order(n);
    
    for (int i=0; i<n; i++) {
        cin >> b[i];
        b[i] -= 1;
        order[b[i]] = i;
    }
    
    for (int i=0; i<n; i++) {
        sort(a[i].begin(), a[i].end(), [&](const int &u, const int &v) {
            return order[u] < order[v];
        });
    }
    
    vector<int> bfs_order;
    queue<int> q;
    q.push(0);
    check[0] = true;
    
    while (!q.empty()) {
        int x = q.front(); q.pop();
        bfs_order.push_back(x);
        for (int y : a[x]) {
            if (check[y] == false) {
                check[y] = true;
                q.push(y);
            }
        }
    }
    
    if (bfs_order == b) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    
    return 0;
}

//	int m = 1; // ť�� ũ�� 
//	for(int i=0; i<n; i++){
//		if(q.empty()) // ���� BFS�� ���� ���ε� ť�� ������� 
//		int x = q.front(); q.pop(); // �տ� ���� �ϳ� ���� 
//		if(x != order[i]) // ������ �ùٸ��� ���� 
//		int cnt = 0; // �̹��� ť�� �־�� �� ������ �� 
//		for(int y : a[x]){ // x�� ����� ��� y�� ���ؼ� 
//			if(checc[y] == false){ // �湮���� ���� ��� 
//				parent[y] = x; // x �� y�� ���� �湮�ؾ��� 
//				cnt += 1;
//			}
//		}
//		for(int j=0; j<cnt; j++){
//			// X�� ������� ���� ������ ť�� �������� �ùٸ��� ���� 
//			if(m+j >= n || parent[order[m+j]] != x)
//			q.push(order[m+j]); check[order[m+j]] = true; // q�� �ְ�, �湮 üũ 
//		}
//		m += cnt;
//	}
	
