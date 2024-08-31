#include <iostream>
#include <algorithm>
#include <stack> 

using namespace std;

// ���� �켱 Ž�� DFS (Depth-First Search)
// ��� �Լ��� �̿��� ���� 

// ���� ����� �̿��� ���� (2���� �迭) 
void dfs(int x){ // dfs(x) : x �� �湮 
	check[x] = true
	for(int i=1; i<=n; i++){
		if(a[x][i] == 1 && check[i] == false){ // ������ �ְ� �湮�� ���� ���� ��� 
			dfs(i);
		}
	}
}
// O( V��) �̴�, ��� ������ �� ��ȸ�غ��� �ϱ� ������ 
// dfs �ϳ� �� ���⵵ : V -> V x O(V) = O( V��) 

// ���� ����Ʈ�� �̿��� ���� (1���� �迭) 
void dfs(int x){ // dfs(x) : x �� �湮 
	check[x] = true
	for(int i=0; i<=a[x].size(); i++){
		int y = a[x][i];
		if(check[y] == false){
			dfs(y);
		}	
	}
}
// O( V + E ) �̴�, ������ �� ���ϸ� ������ ������ ���� ���� ( E : ���� ) 

int main(){
	
	
	
	return 0;
}
