from collections import deque

n, score, p = map(int, input().split())

if n == 0: # 값을 아예 안 넣을 경우
    print(1)
    exit()

arr = list(map(int, input().split()))

arr.sort(reverse=True)

if n == p and score <= arr[-1]: # 랭킹이 다찬 상태에서 가장 작은 수 보다 작으면
    print(-1)
    exit()

rank = 1

for i in range(n):
    if arr[i] > score:
        rank += 1

print(rank)