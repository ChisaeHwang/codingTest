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
		else // ���̳ʽ��� �ޱ� ���ؼ� temp�� ���� �� �� ���鸶�� �����ش� 
		{
			tmep += s[i];
		}
	}
	
	v.push_back(atoi(tmep.c_str())); // ���������� ������ ���⿡ ���� �߰����ش� 
	
	sort(v.begin(), v.end());
 	// greater<int> �Լ��� ����ϸ� ���������� ������ 
	
	answer += to_string(v.front()) + " " +to_string(v.back());
    
    cout << answer << '\n';
	
	return 0;
} 
