n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]

dx = [-1, 0, 1]  # 오른쪽 위, 오른쪽, 오른쪽 아래
dy = [1, 1, 1]  # 위, 그대로, 아래

def dfs(x, y):

    if y == m-1:
        return True

    for i in range(3):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == '.':
            board[nx][ny] = 'o'
    
            if dfs(nx, ny):
                return True
                
    return False

answer = 0
# 첫 번째 열의 각 행에서 시작
for i in range(n):
    if board[i][0] == '.':
        board[i][0] = 'o' 
        if dfs(i, 0):
            answer += 1

print(answer)