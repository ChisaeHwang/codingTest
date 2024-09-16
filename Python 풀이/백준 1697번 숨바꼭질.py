from collections import deque


def bfs(n,  m):
    visited = [False] * 100001
    queue = deque([(n, 0)])
    visited[n] = True

    while queue:
        x, cnt = queue.popleft()
        
        if x == m:
            return cnt

        for nx in (x-1, x+1, x*2):
            if 0 <= nx <= 100000 and not visited[nx]:
                visited[nx] = True
                queue.append((nx, cnt + 1))       


# 입력 받기
n, m = map(int, input().split())
print(bfs(n, m))