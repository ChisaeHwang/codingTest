#include <bits/stdc++.h>

using namespace std;

int nextNum[1000001][11];
string n;
int k;

// 문제의 주 키워드는 k번 아무 숫자나 바꿔서
// 가장 크게 되는 숫자 가져오기

int dfs(string num, int depth) {
  if(depth == 0) { // k번 완료하면 num 발행
    return stoi(num);
  }

  int curN = stoi(num); // 현재 숫자 발행
  if (0 <= nextNum[curN][depth]) // 중복 체크
      return nextNum[curN][depth];

  int maxNum = -1;

  for(int i = 0; i < n.length(); i++) {
    for(int j = i + 1; j < n.length(); j++) {

      if(n[j] == '0' && i == 0) {
        continue;
      } // 가장큰 자릿수는 절대 0과 교환 X

      swap(n[i], n[j]);
      int temp = dfs(n, depth - 1); 
      maxNum = max(maxNum, temp); // 큰 숫자 찾기
      swap(n[i], n[j]);
    }
  } 

  nextNum[curN][depth] = maxNum; // 중복 갱신

  return maxNum;
}

int main() {

  cin >> n >> k;

  memset(nextNum, -1, sizeof(nextNum));

  int ret = dfs(n, k);

  cout << ret << '\n';
  
  return 0;
}
