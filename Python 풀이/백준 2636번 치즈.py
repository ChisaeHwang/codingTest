from collections import deque
import heapq

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

dx = [1, -1, 0, 0] # 동 서 남 북
dy = [0, 0, 1, -1]

# BFS 시작
# visited
# temp board 선언
# - 임시 배열으로 치즈가 녹은 값을 넣고 bfs가 다 끝나면 상태 업데이트
#   - 치즈가 동시에 녹아야 하기 때문에
# 반복

def bfs(sx, sy, board):
    
    visited = [[False] * m for _ in range(n)]
    temp = [[board[i][j] for j in range(m)] for i in range(n)]

    q = deque()
    q.append((sx, sy))
    visited[sx][sy] = True

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
                
                visited[nx][ny] = True

                if board[nx][ny] == 1:
                    temp[nx][ny] = 0
                else:
                    q.append((nx, ny))

    return temp


remain_che = sum(row.count(1) for row in board)
cnt = 0

while True:

    cnt += 1

    board = bfs(0, 0, board)

    if sum(row.count(1) for row in board) == 0: # 치즈가 없을 경우
        break

    remain_che = sum(row.count(1) for row in board)

print(cnt)
print(remain_che)