#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10000000]; // ������ ũ�⸦ �����ϴ� �迭, �ִ� 1õ�� ��
vector<int> lis; // LIS�� ������ ����

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        // ���� Ž������ ���� ������ ũ�Ⱑ �� ��ġ�� ã��
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        
        // ���� LIS�� ���� �����ߴٸ�, ���� ������ ũ�⸦ �߰�
        if (it == lis.end()) {
            lis.push_back(arr[i]);
        } else {
            // �̹� �����ϴ� ��ġ���, �ش� ��ġ�� ���� ������ ũ��� ����
            *it = arr[i];
        }
    }

    // LIS�� ���̰� �� �� �ٿ� ���� �� �ִ� �ִ� ���� ����
    cout << lis.size() << '\n';

    return 0;
}

