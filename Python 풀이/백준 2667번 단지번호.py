from collections import deque

def bfs(arr, x, y, visited):
    queue = deque([(x, y)])
    visited[x][y] = True
    direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    cnt = 1

    while queue:
        x, y = queue.popleft()
        
        for dx, dy in direction:
            nx = x + dx
            ny = y + dy

            if 0 <= nx < n and 0 <= ny < n and arr[nx][ny] == 1 and not visited[nx][ny]:
                visited[nx][ny] = True
                queue.append((nx, ny))
                cnt += 1

    
    return cnt;



n = int(input())
arr = [list(map(int, input().strip())) for _ in range(n)]
visited = [[False] * n for _ in range(n)]
ret = []

for i in range(n):
    for j in range(n):
        if arr[i][j] == 1 and not visited[i][j]:
            ret.append(bfs(arr, i, j, visited))

ret.sort()
print(len(ret))
for i in ret:
    print(i)

