from collections import deque
import sys
input = sys.stdin.readline  # 빠른 입력을 위해 추가

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

virus = []

for i in range(n):
    for j in range(m):
        if board[i][j] == 2:
            virus.append((i, j)) # 튜퓰로 저장  

ans = 0

def make_wall(cnt, sx, sy):
    global ans

    if cnt == 3:
        # 맵 복사 (원본 보존을 위해)
        temp_board = [row[:] for row in board]
        temp_cnt = bfs(temp_board)
        ans = max(ans, temp_cnt)
        return

    for i in range(sx, n): # 행
        if i != sx: # 행이 바뀌면 열 초기화
            sy = 0
        for j in range(sy, m):
            if board[i][j] == 0:
                board[i][j] = 1
                make_wall(cnt + 1, i, j + 1)
                board[i][j] = 0


def bfs(temp_board):
    q = deque(virus)
    visited = [[False] * m for _ in range(n)]

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m \
                and not visited[nx][ny] and temp_board[nx][ny] == 0:
                visited[nx][ny] = True
                temp_board[nx][ny] = 2
                q.append((nx, ny))

    cnt = 0
    for i in range(n):
        for j in range(m):
            if temp_board[i][j] == 0:
                cnt += 1

    return cnt

make_wall(0, 0, 0)
print(ans)

