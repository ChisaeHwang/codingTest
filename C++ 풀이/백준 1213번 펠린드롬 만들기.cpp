#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

string s, ret;
int cnt[200], flag;  // 알파벳 저장소 
char mid;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	for(char a : s) cnt[a]++;
	
	for (int i = 'Z'; i >= 'A'; i--) { // 안쪽에서부터 시작 가장 바깥쪽은 무조건 A 이기에 반대면 A 부터 Z까지로 해도됨 
		if (cnt[i]) { // 해당 알파벳이 있을 경우 
			if (cnt[i] & 1) {  // 해당 알파벳의 개수가 홀수 + 이진수로 식별한 홀수 
			 	mid = char(i);
				flag++;
				cnt[i]--;  
			}
			if (flag == 2) break;
			for (int j = 0; j < cnt[i]; j += 2) {
				ret = char(i) + ret;
				ret += char(i);
			}
		}
	}
	
	if (mid) {
		ret.insert(ret.begin() + ret.size() / 2, mid);
	}
	if (flag == 2) cout << "I'm Sorry Hansoo" << '\n';
	else  cout << ret << '\n';
	
	
	return 0;
}
