from collections import deque

n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

visited = [[False] * m for _ in range(n)]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def bfs (x, y):
    queue = deque([(x, y)]) # 큐 선언할 떄만 이후 요소 추가는 대괄호 X
    visited[x][y] = True
    cnt = 1

    while queue:
        x, y = queue.popleft()
        for i in range (4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < n and 0 <= ny < m and arr[nx][ny] == 1 and not visited[nx][ny]:
                queue.append((nx, ny))
                cnt += 1
                visited[nx][ny] = True

    return cnt

cnt = 0
ret = 0

for i in range(n):
    for j in range(m):
        if not visited[i][j] and arr[i][j] == 1:
            ret = max(ret, bfs(i, j))
            cnt += 1

print(cnt)
print(ret) 

