#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10000000]; // 상자의 크기를 저장하는 배열, 최대 1천만 개
vector<int> lis; // LIS를 저장할 벡터

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        // 이진 탐색으로 현재 상자의 크기가 들어갈 위치를 찾음
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        
        // 만약 LIS의 끝에 도달했다면, 현재 상자의 크기를 추가
        if (it == lis.end()) {
            lis.push_back(arr[i]);
        } else {
            // 이미 존재하는 위치라면, 해당 위치를 현재 상자의 크기로 갱신
            *it = arr[i];
        }
    }

    // LIS의 길이가 곧 한 줄에 넣을 수 있는 최대 상자 개수
    cout << lis.size() << '\n';

    return 0;
}

