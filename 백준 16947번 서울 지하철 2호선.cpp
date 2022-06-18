#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> a[3000];
int check[3000];
int dist[3000];

// p -> x -> y
int go(int x, int p){
	// -2: ����Ŭ ã��(���� X),  -1: ����Ŭ �� ã��, 0~n-1: ����Ŭ ã��, ���� �ε���
	if(check[x] == 1) return x; // ���� �ε��� 
	check[x] = 1; 
	for(int y : a[x]){
		if(y == p) continue; // ���� ������ ���� �����̸� �ǳʶٱ� 
		// y -> x, x -> p �� �� 
		int res = go(y, x);
		if(res == -2) return -2; // ���� �ȵǴ� ����Ŭ -2 ���ϱ� 
		if(res >= 0){
			check[x] = 2;
			if(x == res) return -2; // ���� ������ ����Ŭ �������̶� ���� 
			else return res;
		}
	}
	
	return -1;
}

int main(){
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int u, v;
		cin >> u >> v;
		u -= 1; v -= 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	go(0, -1); // ��ȯ�� 2 ����Ŭ 
	queue<int> q;
	for(int i=0; i<n; i++){
		if(check[i] == 2){ // üũ 2 �ΰŸ� 
			dist[i] = 0;
			q.push(i); // ��ȯ�����κ��� ������ �Ÿ��� ���� 
		} else { // ���� ������ �������Ƿ� -1 
			dist[i] = -1;
		}
	}
	
	// BFS �� ��� ���� �Ÿ� ���ϱ� 
	while(!q.empty()){
		int x = q.front(); // ���� ���� ���� x -> y 
		q.pop();
		for(int y : a[x]){ 
			if(dist[y] == -1){ // ������ -1�� �ʱ�ȭ �߱⿡ -1�� ���� �湮�� ������ �ƴ� 
				q.push(y); // �湮�ϰ� 
				dist[y] = dist[x] + 1; // �Ÿ� ������Ʈ �ϰ� 
			}
		}
	}
	
	// �Ÿ� ��� 
	for(int i=0; i<n; i++){
		cout << dist[i] << ' ';
	}
	
	cout << '\n';
	
	return 0;
}  
