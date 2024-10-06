
from collections import deque

def bfs(arr, x, y, visited, is_color = False):
    n = len(arr)
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    queue = deque([(x, y)])
    visited[x][y] = True
    color = arr[x][y]

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                if is_color:
                    if (color == 'R' or color == 'G') and (arr[nx][ny] == 'R' or arr[nx][ny] == 'G'):
                        visited[nx][ny] = True
                        queue.append((nx, ny))
                    elif color == arr[nx][ny]:
                        visited[nx][ny] = True
                        queue.append((nx, ny))
                else:
                    if color == arr[nx][ny]:
                        visited[nx][ny] = True
                        queue.append((nx, ny))
    

def cnt_area(arr, is_color=False):
    n = len(arr)
    cnt = 0
    visited = [[False] * n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                bfs(arr, i, j, visited, is_color)
                cnt += 1

    return cnt


n = int(input())
arr = [list(input().strip()) for _ in range(n)]


normal = cnt_area(arr)
blind = cnt_area(arr, True)

print(normal, blind)