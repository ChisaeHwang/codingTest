import heapq
import sys

input = sys.stdin.readline 

heap = []

n = int(input())

for _ in range(n):
    x = int(input())

    if x == 0:
        if not heap:
            print(0)
        else:
            print(-heapq.heappop(heap)) # 음수로 저장한 값을 다시 양수로
    else:
        heapq.heappush(heap, -x) # 음수로 저장, 최대 힙이기 떄문
