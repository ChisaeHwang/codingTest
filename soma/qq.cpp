#include <bits/stdc++.h>

using namespace std;

int main() {
	
    long long minNum, maxNum;
    
    cin >> minNum >> maxNum;

    vector<int> number(maxNum - minNum + 1, 0);
    
    for (long long i = 2; i * i <= maxNum; i++) {
        long long n = minNum / (i * i); // i의 제곱수의 배수 중 가장 작은값 
        
        if (min % (i * i)) n++; // 바로 나눠 지면 n++하고 시작 

        // i의 제곱수의 배수는 무조건 제곱인 수가 됨 
        while (n * i * i <= max) {
            number[n * i * i - min] = 1; // 제곱인 수 check 
            // min은 min과 max 사이에 속하는지 여부를 저장하는 거임 
            n++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == 0) cnt++;
    }

    cout << cnt << '\n';
    return 0;
}

