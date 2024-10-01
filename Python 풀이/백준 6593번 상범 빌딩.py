from collections import deque

def bfs(L, R, C, arr):

    start = end = None

    for i in range(L): # 층 Z
        for j in range(R): # 가로 X
            for k in range(C): # 세로 Y
                if arr[i][j][k] == 'S':
                    start = (i, j, k)
                elif arr[i][j][k] == "E":
                    end = (i, j, k)

    directions = [(-1, 0, 0), (1, 0, 0), (0, -1, 0), (0, 1, 0), (0, 0, -1), (0, 0, 1)]
    
    queue = deque([(start[0], start[1], start[2], 0)]) # Y, X, Z, Time
    visited = set([(start[0], start[1], start[2])])

    while queue:
        z, x, y, time = queue.popleft()
        if (z, x, y) == end:
            return f"Escaped in {time} minute(s)."

        for dz, dx, dy in directions:
            nz, nx, ny = z + dz, x + dx, y + dy
            if 0 <= nz < L and 0 <= nx < R and 0 <= ny < C and arr[nz][nx][ny] != '#' and (nz, nx, ny) not in visited:
                queue.append((nz, nx, ny, time + 1))
                visited.add((nz, nx, ny))

    return "Trapped!"




while True:
    L, R, C = map(int, input().split())
    if L == 0 and R == 0 and C == 0:
        break
    
    arr = []
    for _ in range(L):
        floor = [list(input().strip()) for _ in range(R)]
        input()  # 층 사이의 빈 줄 처리
        arr.append(floor)
    
    result = bfs(L, R, C, arr)
    print(result)