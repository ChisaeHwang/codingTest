#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// �ʺ� �켱 Ž�� BFS (Breadth-First Search) 
// BFS ��� ����ġ�� 1�� �� �ִ� �Ÿ��� ���� �� �־� �߿��� 
 
int main() {
	
	// BFS�� ������ ť�� �̿��ؼ� �� �� �ִ�. (���� ���)
	queue<int> q;
	check[1] = true; q.push(1); // ������ 
	while(!q.empty()){ // ť�� ��� ���� ���� ���� 
		int x = q.front();
		q.pop(); // ������ X ���� 
		for(int i=1; i<=n; i++){
			if(a[x][i] == 1 && check[i] == false){  // ������ �ְ� �湮�� ���� ���� ��� 
				check[i] = true;
				q.push(i);
			}
		} 
	}
	
	// ���� ����Ʈ
	
	while(!q.empty()){ // ť�� ��� ���� ���� ���� 
		int x = q.front();
		q.pop(); // ������ X ���� 
		for(int i=0; i<a[x].size(); i++){
			int y = a[x][i]
			if(a[x][i] == 1 && check[i] == false){  // ������ �ְ� �湮�� ���� ���� ��� 
				checkyi] = true;
				q.push(y);
			}
		} 
	}
	
	return 0;
} 
