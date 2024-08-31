#include <bits/stdc++.h>

using namespace std;

int arr[51][51];
int visited[51][51];

int main() {
	
	string s;
	string skip;
	int index;
	
	cin >> s >> skip >> index;
	
	for (int i = 0; i < s.length(); i++) {
        int cnt = index;
        while(cnt--) {
            s[i]++;
            if (s[i] > 122) s[i] = 'a';
            for (int j = 0; j < skip.length(); j++) {
                if (s[i] == skip[j]) cnt++;
            }
        }
    }
	
	cout << s << '\n';
	
	
	return 0;
} 
