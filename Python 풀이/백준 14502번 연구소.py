from collections import deque
from itertools import combinations
import copy
import sys
input = sys.stdin.readline 

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 바이러스와 빈 칸의 위치를 미리 저장
virus = []
empty = []
for i in range(n):
    for j in range(m):
        if graph[i][j] == 2:
            virus.append((i, j))
        elif graph[i][j] == 0:
            empty.append((i, j))

def spread_virus():
    queue = deque(virus)
    temp_graph = copy.deepcopy(graph)
    
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and temp_graph[nx][ny] == 0:
                temp_graph[nx][ny] = 2
                queue.append((nx, ny))
    
    return sum(row.count(0) for row in temp_graph)

result = 0
for wall in combinations(empty, 3):
    for x, y in wall:
        graph[x][y] = 1
    
    result = max(result, spread_virus())
    
    for x, y in wall:
        graph[x][y] = 0

print(result)