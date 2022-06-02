#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool check(string &password){
	int ja = 0; // 자음 
	int mo = 0; // 모음
	
	for (char x : password){
		if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
			mo += 1;
		} else {
			ja += 1;
		}
	} 
	
	// 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성
	return ja >= 2 && mo >= 1;
}

// n : 만들어야 하는 암호의 길이
// alpah : 사용할 수 있는 알파벳
// password : 현재까지 만든 암호
// i : 사용할지 말지 결정해야 하는 알파벳의 인덱스 
 
void go(int n, vector<char> &alpah, string password, int i) {
	if(password.length() == n){ // 정답을 찾은 경우 
		if(check(password)){
			cout << password << '\n';	
		} 
		return;
	} 
	
	// 이게 위에 있으면 마지막껄 포함한 암호를 만들 수가 없다 
	if( i >= alpah.size()) return; // 불가능한 경우
	go(n, alpah, password+alpah[i], i+1); // i번째 알파벳을 사용하는 경우 
	go(n, alpah, password, i+1); // i번째 알파벳을 사용하지 않는 경우 
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<char> a(m); // 벡터 크기 설정 
	
	for(int i=0; i<m; i++){
		cin >> a[i];
	}
	
	// 사전식으로 출력 
	sort(a.begin(), a.end());
	
	// 길이, 사용가능한 알파벳, 현재까지 만든 암호, 암호 인덱스 
	go(n, a, "", 0);
	
	return 0;
}
