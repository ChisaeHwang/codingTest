from collections import deque

def bfs(start_x, start_y, height):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    queue = deque([(start_x, start_y)])
    visited[start_x][start_y] = True
    
    while queue:
        x, y = queue.popleft()
        
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny] and area[nx][ny] > height:
                queue.append((nx, ny))
                visited[nx][ny] = True

N = int(input())
area = [list(map(int, input().split())) for _ in range(N)]

ret = 1

for height in range(0, 101):
    visited = [[False] * N for _ in range(N)]
    cnt = 0
    
    for i in range(N):
        for j in range(N):
            # 영역이 겹치면 Visited가 전파됨
            # 즉 물에 안 잠긴 영역이 몇개로 나뉘어졌는지 확인 가능
            # 그리고 매 깊이마다 Visited는 초기화
            if not visited[i][j] and area[i][j] > height: 
                bfs(i, j, height)
                cnt += 1
    
    ret = max(ret, cnt)

print(ret)