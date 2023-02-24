#include <bits/stdc++.h>

using namespace std;

int arr[51][51];
int visited[51][51];

int main() {
	
	string s;
	
	getline(cin, s); 
	
	string answer = "";
	string tmep;
	vector<int> v;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == ' ' )
		{
			v.push_back(atoi(tmep.c_str()));
			tmep.clear();
		}
		else // 마이너스도 받기 위해서 temp를 먼저 한 후 공백마다 더해준다 
		{
			tmep += s[i];
		}
	}
	
	v.push_back(atoi(tmep.c_str())); // 마지막에는 공백이 없기에 따로 추가해준다 
	
	sort(v.begin(), v.end());
 	// greater<int> 함수를 사용하면 내림차순이 가능함 
	
	answer += to_string(v.front()) + " " +to_string(v.back());
    
    cout << answer << '\n';
	
	return 0;
} 
