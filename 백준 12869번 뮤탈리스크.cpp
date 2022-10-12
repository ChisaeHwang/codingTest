#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MOD 1e9

using namespace std;

int n;
int dp[61][61][61];
int hp[3] = {0, };

int go(int x, int y, int z) {
	if(x < 0) return go(0, y, z); // ���� �� �־����ų� �ν����� ��� 
	if(y < 0) return go(x, 0, z);
	if(z < 0) return go(x, y, 0);
	
	if(x == 0 && y == 0 && z == 0) return 0;
	
	int& res = dp[x][y][z]; // ���� hp ��Ȳ ����
	
	if(res != -1) return res; // �̹� ����� ��� ����ó�� (���ʿ��� ��� ����) 
	
	res = MOD; // �ʿ信 ���� res ���� ���� 
	
	res = min(res, go(x - 9, y - 3, z - 1) + 1);
	res = min(res, go(x - 9, y - 1, z - 3) + 1);
	
	res = min(res, go(x - 3, y - 9, z - 1) + 1);
	res = min(res, go(x - 1, y - 9, z - 3) + 1);
	 
	res = min(res, go(x - 3, y - 1, z - 9) + 1);
	res = min(res, go(x - 1, y - 3, z - 9) + 1);
	
	return res;
	 
}

int main() {
	

	cin >> n;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++){
		cin >> hp[i];
	}
	
	cout << go(hp[0], hp[1], hp[2]) << '\n';
	
	return 0;
}
