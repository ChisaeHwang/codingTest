#include <iostream>
using namespace std;

int main(){
    int a, b, c, reward=0;
    cin >> a >> b >> c;
    
    if (a==b && b==c){ //���� ���� 3���� ��
        reward = 10000 + a*1000;
    }
    else if (a==b || a==c){ //���� ���� 2���� ��
        reward = 1000 + a*100;
    }
    else if (b==c){ //���� ���� 2���� ��
        reward = 1000 + b*100;
    }
    else { //��� �ٸ� ���� ��
        reward = max(max(a,b),c) * 100;
    }
    
    cout << reward;
    
    return 0;
} 
