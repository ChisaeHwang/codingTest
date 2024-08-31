from collections import deque

def bfs(arr, start_x, start_y):
    queue = deque([(start_x, start_y)])
    directions = [(1, 0), (0, 1), (-1, 0), (0, -1)] 

    while queue:
        x, y = queue.popleft();

        # 4방향 탐색
        for dx, dy in directions:
            nx, ny = x + dx, y + dy

            if 0 <= nx < n and 0 <= ny < m and arr[nx][ny] == 1:
                # 이전 칸까지의 거리 + 1로 갱신
                arr[nx][ny] = arr[x][y] + 1
                queue.append((nx, ny)) 

    # 목표 지점의 값 반환
    return arr[n - 1][m - 1]



# 입력 받기
n, m = map(int, input().split())
arr = [list(map(int, input().strip())) for _ in range(n)]


# BFS 실행 및 결과 출력
result = bfs(arr, 0, 0)
print(result)