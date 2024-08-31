#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createKaryTree(int N, int K) {
    vector<vector<int>> tree(N + 1); // 트리 구조를 저장하기 위한 벡터

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            int child = i * K - (K - j) + 1;
            if (child > N) break; // N개의 노드를 초과하지 않도록 함
            tree[i].push_back(child); // i번 노드에 자식 노드 추가
        }
    }

    return tree;
}

int main() {
    int N, K;
    cout << "Enter number of nodes (N) and maximum children per node (K): ";
    cin >> N >> K;

    vector<vector<int>> karyTree = createKaryTree(N, K);

    // 트리 출력
    for (int i = 1; i <= N; ++i) {
        cout << "Node " << i << " children: ";
        for (int child : karyTree[i]) {
            cout << child << " ";
        }
        cout << endl;
    }

    return 0;
}

