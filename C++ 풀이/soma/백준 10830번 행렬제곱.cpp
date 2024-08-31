#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000;

// ����� ������ �����ϴ� �Լ�
vector<vector<int>> multiplyMatrix(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int n = a.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

// ���� ������ �̿��Ͽ� ����� �ŵ������� ����ϴ� �Լ�
vector<vector<int>> powerMatrix(vector<vector<int>> matrix, long long power) {
    int n = matrix.size();
    vector<vector<int>> result(n, vector<int>(n));

    // ���� ��ķ� �ʱ�ȭ
    for (int i = 0; i < n; ++i)
        result[i][i] = 1;

    while (power > 0) {
        if (power % 2 == 1)
            result = multiplyMatrix(result, matrix);
        matrix = multiplyMatrix(matrix, matrix);
        power /= 2;
    }

    return result;
}

int main() {
    int n;
    long long b;
    cin >> n >> b;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    vector<vector<int>> result = powerMatrix(matrix, b);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << result[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

