import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())

    score = [list(map(int, input().split())) for _ in range(n)]
    score.sort(key=lambda x: x[0])

    ret = 1
    min_score = score[0][1]

    for i in range(1, n):
        if score[i][1] < min_score:
            ret += 1
            min_score = score[i][1]

    print(ret)

