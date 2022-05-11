#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
  if(a.first < b.first){
    return true;
  }

  else if(a.first == b.first){
    return (a.second < b.second);
  }
  else {
    return false;
  }
}

int main() {

  int n, nX, nY;
  vector <pair<int, int>> v;
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> nX >> nY;
    v.push_back(pair<int, int>(nX, nY));
  }

  sort(v.begin(), v.end(), cmp);

  for(int i=0; i<n; i++){
    cout << v.at(i).first << " " <<v.at(i).second << '\n';
  }

  return 0;
}