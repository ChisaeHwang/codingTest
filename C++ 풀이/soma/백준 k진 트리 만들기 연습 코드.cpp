#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createKaryTree(int N, int K) {
    vector<vector<int>> tree(N + 1); // Ʈ�� ������ �����ϱ� ���� ����

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            int child = i * K - (K - j) + 1;
            if (child > N) break; // N���� ��带 �ʰ����� �ʵ��� ��
            tree[i].push_back(child); // i�� ��忡 �ڽ� ��� �߰�
        }
    }

    return tree;
}

int main() {
    int N, K;
    cout << "Enter number of nodes (N) and maximum children per node (K): ";
    cin >> N >> K;

    vector<vector<int>> karyTree = createKaryTree(N, K);

    // Ʈ�� ���
    for (int i = 1; i <= N; ++i) {
        cout << "Node " << i << " children: ";
        for (int child : karyTree[i]) {
            cout << child << " ";
        }
        cout << endl;
    }

    return 0;
}

