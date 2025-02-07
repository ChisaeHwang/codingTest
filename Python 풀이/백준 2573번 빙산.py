from collections import deque
import heapq
from copy import deepcopy

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

icebergs = [] # x, y, 빙산 높이

dx = [1, -1, 0, 0] # 동 서 남 북
dy = [0, 0, 1, -1]

for i in range(n):
    for j in range(m):
        if board[i][j] > 0:
            icebergs.append((i, j, board[i][j]))

def melt_ice():
    global icebergs

    # temp = deepcopy(temp) 이것도 됨
    temp = [[board[i][j] for j in range(m)] for i in range(n)]
    new_icebergs = []

    for x, y, h in icebergs:
        if h <= 0:
            continue

        cnt = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 0:
                cnt += 1

        new_h = max(0, h - cnt)  # max로 음수 방지
        temp[x][y] = new_h
        if new_h > 0:  # 0보다 큰 경우만 새 리스트에 추가
            new_icebergs.append((x, y, new_h))
            
    icebergs = new_icebergs
    return temp


def bfs(x, y, visited):
    q = deque([(x, y)])
    visited[x][y] = True
    count = 1  # 현재 덩어리의 빙산 개수

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and board[nx][ny] > 0:
                visited[nx][ny] = True
                q.append((nx, ny))
                count += 1
    
    return count  # 덩어리의 빙산 개수 반환


time = 0

while True:
    board = melt_ice()
    time += 1

    if not icebergs:
        print(0)
        break

    visited = [[False] * m for _ in range(n)]
    first_count = 0
    
    # 첫 번째 빙산 찾기
    for x, y, h in icebergs:
        if h > 0:
            first_count = bfs(x, y, visited)
            break
    
    # 방문하지 않은 빙산이 있다면 두 덩어리 이상
    total_count = 0
    for x, y, h in icebergs:
        if h > 0:
            total_count += 1
    
    if first_count < total_count:
        print(time)
        break