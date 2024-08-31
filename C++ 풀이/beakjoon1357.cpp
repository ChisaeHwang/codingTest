// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n, m;

int Rev(int n) {

    int sum = 0;
    while(n) { // n의 값이 0이 될때까지 계속 나누다 보면 n은 0이됨
        sum = sum * 10 + n%10; // sum의 가장 작은값이 남게되고 이미 있는 sum값은 *10 해서 rev해준다
        n /= 10;
    }

    return sum;
}

int main() {

    cin >> n >> m;

    cout << Rev(Rev(n) + Rev(m)) << '\n';


    return 0;
}



