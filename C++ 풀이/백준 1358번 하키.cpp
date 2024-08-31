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

    int W, H, X, Y, P, cnt = 0; // 너비, 높이, x, y, 선수의 수
    cin >> W >> H >> X >> Y >> P;

    for (int t = 0; t < P; ++t) {
        int x, y, r = (H / 2) * (H / 2);
        
        cin >> x >> y;
    
        // 사각형 안에 있는지 판별
        if (X <= x && x <= X + W && Y <= y && y <= Y + H)
            cnt++;
        // 왼쪽 반원에 있는지 판별
        else if (calc_dist(X, Y + (H / 2), x, y) <= r)
            cnt++;
        // 오른쪽 반원에 있는지 판별
        else if (calc_dist(X + W, Y + (H / 2), x, y) <= r)  
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
