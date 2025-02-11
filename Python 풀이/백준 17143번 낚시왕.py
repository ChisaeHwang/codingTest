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
            dist_to_top = x  # 위쪽 끝까지 거리
            if s <= dist_to_top:  # 위로 이동 가능
                x -= s
            else:  # 위로 못감
                remain = s - dist_to_top  # 위로 이동하고 남은 거리
                x = 0  # 일단 위쪽 끝으로
                d = 2  # 아래 방향으로
                x += remain  # 아래로 남은 거리만큼
                
                if x >= R:  # 아래쪽 끝을 넘어가면
                    x = 2 * (R-1) - x  # 넘어간 만큼 (R-1에서 뺌)
                    d = 1  # 다시 위로
                    
        else:  # 아래
            dist_to_bottom = R-1-x  # 아래쪽 끝까지 거리
            if s <= dist_to_bottom:  # 아래로 이동 가능
                x += s
            else:  # 아래로 못감
                remain = s - dist_to_bottom  # 아래로 이동하고 남은 거리
                x = R-1  # 일단 아래쪽 끝으로
                d = 1  # 위 방향으로
                x -= remain  # 위로 남은 거리만큼
                
                if x < 0:  # 위쪽 끝을 넘어가면
                    x = abs(x)  # 넘어간 만큼
                    d = 2  # 다시 아래로
                    
    else:  # 좌우 이동
        cycle = 2 * (C - 1)
        s = s % cycle
        
        if d == 3:  # 오른쪽
            dist_to_right = C-1-y  # 오른쪽 끝까지 거리
            if s <= dist_to_right:  # 오른쪽으로 이동 가능
                y += s
            else:  # 오른쪽으로 못감
                remain = s - dist_to_right  # 오른쪽으로 이동하고 남은 거리
                y = C-1  # 일단 오른쪽 끝으로
                d = 4  # 왼쪽 방향으로
                y -= remain  # 왼쪽으로 남은 거리만큼
                
                if y < 0:  # 왼쪽 끝을 넘어가면
                    y = abs(y)  # 넘어간 만큼
                    d = 3  # 다시 오른쪽으로
                    
        else:  # 왼쪽
            dist_to_left = y  # 왼쪽 끝까지 거리
            if s <= dist_to_left:  # 왼쪽으로 이동 가능
                y -= s
            else:  # 왼쪽으로 못감
                remain = s - dist_to_left  # 왼쪽으로 이동하고 남은 거리
                y = 0  # 일단 왼쪽 끝으로
                d = 3  # 오른쪽 방향으로
                y += remain  # 오른쪽으로 남은 거리만큼
                
                if y >= C:  # 오른쪽 끝을 넘어가면
                    y = 2 * (C-1) - y  # 넘어간 만큼 (C-1에서 뺌)
                    d = 4  # 다시 왼쪽으로
    
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