
board = [list(map(int, input().split())) for _ in range(19)]

# 오른쪽, 아래, 오른쪽아래대각선, 오른쪽위대각선
dx = [0, 1, 1, -1]
dy = [1, 0, 1, 1]

def find_5line(case, x, y):
    
    for i in range(4): # 4방향만 탐색하면 됨 어차피

        cnt = 1
        nx = x 
        ny = y 

        for _ in range(4): # 5목인 경우 탐색
            nx += dx[i]
            ny += dy[i]

            if nx < 0 or nx >= 19 or ny < 0 or ny >= 19:
                break

            if board[nx][ny] != case:
                break
            
            cnt += 1

        if cnt == 5:

            # 기존에 6목이 다음 탐색에선 5목이 될 수 있어서 그 뒤에 있는 것도 탐색해야함
            px = x - dx[i]  # 뒤로 한 칸
            py = y - dy[i]
            if 0 <= px < 19 and 0 <= py < 19 and board[px][py] == case:
                continue

            nx += dx[i]
            ny += dy[i]

            # 스택오버플로우 방지를 위해서 안전하게 체크
            if 0 <= nx < 19 and 0 <= ny < 19 and board[nx][ny] == case:
                 continue

            return True

    return False


winner = 0
winner_x = 0
winner_y = 0

for i in range(19):
    for j in range(19):
        if board[i][j] == 1:
            if find_5line(1, i, j):
                winner = 1
                winner_x = i + 1 # 문제에서는 1부터 시작 *인덱스 고려
                winner_y = j + 1
                break
        elif board[i][j] == 2:
            if find_5line(2, i, j):
                winner = 2
                winner_x = i + 1
                winner_y = j + 1
                break
    if winner != 0:
        break

print(winner)
if winner != 0:
    print(winner_x, winner_y)
