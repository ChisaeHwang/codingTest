n, k = map(int, input().split())

v = []
w = []

for _ in range(n):
    W, V = map(int, input().split())
    w.append(W)
    v.append(V)


# DP 테이블 초기화
dp = [[0] * (k + 1) for _ in range(n + 1)]

# DP 테이블 업데이트
for i in range(1, n + 1):
    for j in range(k + 1):
        if w[i - 1] <= j:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1])
        else:
            dp[i][j] = dp[i - 1][j]

print(dp[n][k])