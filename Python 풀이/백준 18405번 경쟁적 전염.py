from collections import deque
import heapq

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

n, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
s, x, y = map(int, input().split())

# 첫 번째 풀이
# 한 개는 임시배열을 선언해서 시간(time)을 넣어두고
# 큰 바이러스 순으로 실행해서 board를 매타임 갱신하는 느낌
# 3 → 2 → 1 순으로 실행 time이 겹치거나 작으면 더 작은 수가 차지하는 느낌
# 
# 두 번째 풀이 (선택)
# Deque의 FIFO를 이용하는 방법
# 처음 입력한 값이 처음으로 나오는 특성을 이용
# "정렬 사용하면 끝"
# [1, 2, 3] → [2, 3, 1-1] → [3, 1-1, 2-1]
# → [1-1, 2-1, 3-1] → [2-1, 3-1, 1-2] 느낌  

virus = []

# 바이러스, x, y, 시간
for i in range(n):
    for j in range(n):
        if board[i][j] != 0: # 빈공간이 아닌 경우
            virus.append((board[i][j], i, j, 0))

virus.sort()

visited = [[False] * n for _ in range(n)]
for _, i, j, _ in virus: # 바이러스는 체크
    visited[i][j] = True 

def bfs():
    
    q = deque(virus)
    
    while q:
        virus_num, x, y, time = q.popleft()

        if time >= s:
            continue

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                visited[nx][ny] = True
                board[nx][ny] = virus_num
                q.append((virus_num, nx, ny, time + 1))

bfs()

print(board[x - 1][y - 1])
