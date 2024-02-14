#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[1001];
int n;

vector<string> split(const string s, char delimiter) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(s);
  
  while(getline(tokenStream, token, delimiter)) {
  	tokens.push_back(token);
  }
  
  return tokens;
}

int main() {
    
    cin >> n;
    
    string str = "This is a sample string";
    char delimiter = ' '; // 공백을 구분자로 사용
    vector<string> splitStr = split(str, delimiter);

    for (const auto &s : splitStr) {
        cout << s << std::endl;
    }
    
    return 0;
}

