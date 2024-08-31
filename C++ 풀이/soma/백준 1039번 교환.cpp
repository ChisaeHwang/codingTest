#include <bits/stdc++.h>

using namespace std;

int nextNum[1000001][11];
string n;
int k;

// ������ �� Ű����� k�� �ƹ� ���ڳ� �ٲ㼭
// ���� ũ�� �Ǵ� ���� ��������

int dfs(string num, int depth) {
  if(depth == 0) { // k�� �Ϸ��ϸ� num ����
    return stoi(num);
  }

  int curN = stoi(num); // ���� ���� ����
  if (0 <= nextNum[curN][depth]) // �ߺ� üũ
      return nextNum[curN][depth];

  int maxNum = -1;

  for(int i = 0; i < n.length(); i++) {
    for(int j = i + 1; j < n.length(); j++) {

      if(n[j] == '0' && i == 0) {
        continue;
      } // ����ū �ڸ����� ���� 0�� ��ȯ X

      swap(n[i], n[j]);
      int temp = dfs(n, depth - 1); 
      maxNum = max(maxNum, temp); // ū ���� ã��
      swap(n[i], n[j]);
    }
  } 

  nextNum[curN][depth] = maxNum; // �ߺ� ����

  return maxNum;
}

int main() {

  cin >> n >> k;

  memset(nextNum, -1, sizeof(nextNum));

  int ret = dfs(n, k);

  cout << ret << '\n';
  
  return 0;
}
