from collections import deque
import heapq

n, l, r = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

day = 0

dx = [1, -1, 0, 0]  # 동 서 남 북
dy = [0, 0, 1, -1]

def bfs(sx, sy, visited):

    q = deque()
    q.append((sx, sy))
    visited[sx][sy] = True
    move = False
    country = deque()
    country_sum = board[sx][sy]
    country.append((sx, sy))

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]


            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:

                next_country = abs(board[x][y] - board[nx][ny])

                if l <= next_country <= r:
                    move = True
                    visited[nx][ny] = True
                    country_sum += board[nx][ny]
                    country.append((nx, ny))
                    q.append((nx, ny))

    division_country = country_sum // len(country)

    for x, y in country:
        board[x][y] = division_country


    if move: # 국경선이 열리면 True 반환
        return True

    # 없을 경우 False 반환
    return False

while True:
    # 국경선 열리는지 체크
    move = False
    visited = [[False] * n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                if bfs(i, j, visited):
                    move = True

    if not move:
        break

    day += 1

print(day)