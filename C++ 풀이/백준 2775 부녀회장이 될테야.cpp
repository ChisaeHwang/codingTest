#include <iostream>

using namespace std;

int T;
int arr[15][15];

int main() {
    cin >> T;

    //�ʱ�ȭ
    for(int i=0;i<15;i++) 
        arr[0][i]=i;

    //�ٷ� �Ʒ��� ���
    for(int i=1;i<15;i++)
        for(int j=1;j<15;j++)
            for(int k=1;k<=j;k++)
                arr[i][j]+=arr[i-1][k]; 

    while(T--) {
        int K, N;
        cin >> K >> N;
        cout <<arr[K][N]<< "\n"; //��� ���
    }
}
