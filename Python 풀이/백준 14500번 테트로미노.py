n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0] # 위, 아래, 오른쪽, 왼쪽
answer = 0

def dfs(cnt, temp, x, y): # 카운트, 합, 위치
    global answer

    if cnt == 4: # 4칸 선택 완료
        answer = max(answer, temp)
        return
    
    # ㅗ 모양 처리 (첫 번째 블록 선택 후)
    if cnt == 1:
        for d in range(4):  # 4가지 방향의 ㅗ,ㅜ,ㅏ,ㅓ 체크
            temp_sum = temp  # 현재 값
            flag = True
            for k in range(3):  # 연속된 3방향 체크
                t = (d + k) % 4
                nx = x + dx[t]
                ny = y + dy[t]
                
                if not (0 <= nx < n and 0 <= ny < m):
                    flag = False
                    break
                temp_sum += board[nx][ny]
            
            if flag:
                answer = max(answer, temp_sum)
    
    # 일반적인 테트로미노 처리
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
            visited[nx][ny] = True
            dfs(cnt + 1, temp + board[nx][ny], nx, ny)
            visited[nx][ny] = False

# 모든 시작점에 대해 DFS 수행
for i in range(n):
    for j in range(m):
        visited[i][j] = True
        dfs(1, board[i][j], i, j)
        visited[i][j] = False

print(answer)