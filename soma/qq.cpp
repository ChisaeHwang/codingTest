#include <bits/stdc++.h>

using namespace std;

int main() {
	
    long long minNum, maxNum;
    
    cin >> minNum >> maxNum;

    vector<int> number(maxNum - minNum + 1, 0);
    
    for (long long i = 2; i * i <= maxNum; i++) {
        long long n = minNum / (i * i); // i�� �������� ��� �� ���� ������ 
        
        if (min % (i * i)) n++; // �ٷ� ���� ���� n++�ϰ� ���� 

        // i�� �������� ����� ������ ������ ���� �� 
        while (n * i * i <= max) {
            number[n * i * i - min] = 1; // ������ �� check 
            // min�� min�� max ���̿� ���ϴ��� ���θ� �����ϴ� ���� 
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

