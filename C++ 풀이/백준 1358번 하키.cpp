#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int calc_dist(int x, int y, int a, int b) {
    return ((x - a) * (x - a)) + ((b - y) * (b - y));
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    init();

    int W, H, X, Y, P, cnt = 0; // �ʺ�, ����, x, y, ������ ��
    cin >> W >> H >> X >> Y >> P;

    for (int t = 0; t < P; ++t) {
        int x, y, r = (H / 2) * (H / 2);
        
        cin >> x >> y;
    
        // �簢�� �ȿ� �ִ��� �Ǻ�
        if (X <= x && x <= X + W && Y <= y && y <= Y + H)
            cnt++;
        // ���� �ݿ��� �ִ��� �Ǻ�
        else if (calc_dist(X, Y + (H / 2), x, y) <= r)
            cnt++;
        // ������ �ݿ��� �ִ��� �Ǻ�
        else if (calc_dist(X + W, Y + (H / 2), x, y) <= r)  
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
