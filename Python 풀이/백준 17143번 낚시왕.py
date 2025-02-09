R, C, M = map(int, input().split())
board = [[0] * C for _ in range(R)]

dx = [-1, 1, 0, 0]  # 위 아래 오른쪽 왼쪽
dy = [0, 0, 1, -1]

for i in range(M):
    r, c, s, d, z = map(int, input().split())
    board[r-1][c-1] = (s, d, z)

directions = {
    1: 2, 2: 1, 3: 4, 4: 3
}

def move_shark(x, y, s, d):
    if d <= 2:  # 상하 이동
        cycle = 2 * (R - 1)
        s = s % cycle
        
        if d == 1:  # 위
            if s <= x:  # 위로 s만큼 이동 가능
                x -= s
            else:  # 위로 못감
                s -= x  # 위로 이동한 만큼 빼기
                if s <= R-1:  # 아래로 이동 가능
                    d = 2
                    x = s
                else:  # 다시 위로
                    x = R-1 - (s - (R-1))
                    d = 1
        else:  # 아래
            if s <= R-1-x:  # 아래로 이동 가능
                x += s
            else:  # 아래로 못감
                s -= (R-1-x)  # 아래로 이동한 만큼 빼기
                if s <= R-1:  # 위로 이동 가능
                    d = 1
                    x = R-1 - s
                else:  # 다시 아래로
                    x = s - (R-1)
                    d = 2
                    
    else:  # 좌우 이동
        cycle = 2 * (C - 1)
        s = s % cycle
        
        if d == 3:  # 오른쪽
            if s <= C-1-y:  # 오른쪽으로 이동 가능
                y += s
            else:  # 오른쪽으로 못감
                s -= (C-1-y)  # 오른쪽으로 이동한 만큼 빼기
                if s <= C-1:  # 왼쪽으로 이동 가능
                    d = 4
                    y = C-1 - s
                else:  # 다시 오른쪽으로
                    y = s - (C-1)
                    d = 3
        else:  # 왼쪽
            if s <= y:  # 왼쪽으로 이동 가능
                y -= s
            else:  # 왼쪽으로 못감
                s -= y  # 왼쪽으로 이동한 만큼 빼기
                if s <= C-1:  # 오른쪽으로 이동 가능
                    d = 3
                    y = s
                else:  # 다시 왼쪽으로
                    y = C-1 - (s - (C-1))
                    d = 4
    
    return x, y, d

def move_sharks():
    new_board = [[0] * C for _ in range(R)]
    sharks = []
    
    for i in range(R):
        for j in range(C):
            if board[i][j]:
                s, d, z = board[i][j]
                nx, ny, new_d = move_shark(i, j, s, d)
                sharks.append((nx, ny, s, new_d, z))
    
    for x, y, s, d, z in sharks:
        if new_board[x][y]:
            prev_s, prev_d, prev_z = new_board[x][y]
            if z > prev_z:
                new_board[x][y] = (s, d, z)
        else:
            new_board[x][y] = (s, d, z)
    
    return new_board

# 낚시왕의 이동과 상어 잡기
answer = 0
for j in range(C):  # 낚시왕이 오른쪽으로 이동
    # 가장 가까운 상어 잡기
    for i in range(R):
        if board[i][j]:  # 상어 발견
            s, d, z = board[i][j]
            answer += z  
            board[i][j] = 0  # 상어 제거
            break
    
    # 상어 이동
    board = move_sharks()

print(answer)