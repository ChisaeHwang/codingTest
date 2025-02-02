
n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

ans = 0

def dfs(cnt, temp, x, y): # 카운트, 합, 위치
    global ans

    if cnt == 4:
        ans = max(ans, temp)
        return

    if cnt == 1: # ㅗ, ㅜ, ㅓ, ㅑ 방향 체크
        for i in range(4): # 4방향 체크
            temp_sume = temp
            flag = False
            for d in range(3): # 현재 방향에서 각각 3개씩 뻗어나가기
                t = (d + i) % 4
                nx = x + dx[t]
                ny = y + dy[t]
                if not (0 <= nx < n and 0 <= ny < m): # 범위를 벗어날 경우
                    flag = True
                    break
                temp_sume += board[nx][ny]

            if flag == True:
                ans = max(ans, temp_sume)

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
            visited[nx][ny] = True
            dfs(cnt + 1, temp + board[nx][ny], nx, ny)
            visited[nx][ny] = False

for i in range(n):
    for j in range(m):
        visited[i][j] = True
        dfs(1, board[i][j], i, j)
        visited[i][j] = False

print(ans)


