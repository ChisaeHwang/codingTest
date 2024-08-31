#include <bits/stdc++.h>

using namespace std;

string s, t;
bool check = false;

void solve(string a) {
    if(a == s) {
        check = true;
        return;
    }

    if(a.size() < s.size()) return; 

    if (a.back() == 'A') {
        a.pop_back();
        solve(a);
        a.push_back('A');
    }
   if (a[0] == 'B') {
        reverse(a.begin(), a.end());
        a.pop_back();
        solve(a);
    }
}

int main() {
    cin >> s >> t;
    solve(t);
    
    if(check) {
        cout << 1;
    } else {
        cout << 0;
    }
    
    return 0;
}

