import copy

# ↑, ↖, ←, ↙, ↓, ↘, →, ↗
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, -1, -1, -1, 0, 1, 1, 1]

# 물고기 이동
def move_fish(sx, sy, board):

    for fish in range(1, 17):
        fish_x, fish_y = -1, -1
        for x in range(4):
            for y in range(4):
                if board[x][y][0] == fish: # 해당번호 물고기가 있으면
                    fish_x, fish_y = x, y
                    break
        
        if fish_x == -1:  # 물고기가 없는 경우
            continue
            
        # 물고기의 방향
        direction = board[fish_x][fish_y][1]

        for i in range(8):
            nd = (direction + i) % 8  # 반시계 45도씩 회전
            nx = fish_x + dx[nd]
            ny = fish_y + dy[nd]
            

            if 0 <= nx < 4 and 0 <= ny < 4 and (nx, ny) != (sx, sy): # 상어위치는 생략
                # 물고기 위치 교환
                board[fish_x][fish_y] = (board[fish_x][fish_y][0], nd)
                board[fish_x][fish_y], board[nx][ny] = board[nx][ny], board[fish_x][fish_y]
                break

def solve(x, y, score, board):
    global answer
    score += board[x][y][0]  # 현재 위치 물고기 먹기
    answer = max(answer, score)  # 최대값 갱신
    
    board[x][y] = (0, board[x][y][1])  # 물고기 제거
    
    # 물고기 이동
    move_fish(x, y, board)
    
    direction = board[x][y][1]  # 현재 상어의 방향
    
    # 1칸, 2칸, 3칸 이동 가능
    for i in range(1, 4):
        nx = x + dx[direction] * i
        ny = y + dy[direction] * i
        
        # 범위 내이고 물고기가 있는 칸
        if 0 <= nx < 4 and 0 <= ny < 4 and board[nx][ny][0] > 0:
            solve(nx, ny, score, copy.deepcopy(board))


board = []
for i in range(4):
    row = list(map(int, input().split()))
    temp = []
    for j in range(0, 8, 2):
        # (물고기 번호, 방향-1) 형태로 저장
        temp.append((row[j], row[j+1]-1))
    board.append(temp)

answer = 0
solve(0, 0, 0, board)
print(answer)