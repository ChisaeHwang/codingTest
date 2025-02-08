from collections import deque
import heapq

n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]

dx = [1, -1, 0, 0] # 동 서 남 북
dy = [0, 0, 1, -1]

# bfs로 실행
# 겹치는 경우 움직인 횟수가 더 적은게 움직인 방향 -1

# 시뮬레이션 시작
# 10번 이상 실행할 경우 break -1 출력
# 현재 빨간 구슬(r), 파란 구슬(b) 위치 확인
# 동서남북 순으로 기울이기
# - 현재 구슬 위치 기준으로 이동
# - 이때 벽을 만나거나 구멍에 빠지면 그만두기
#   - 벽을 만나거나 구멍에 빠질 때까지의 움직인 길이 반환
#   - r, b 따로 따로 실행 위치 반환 및 움직인 길이 반환
# 만약 r, b 위치가 같을 경우 
# 길이가 적은 구슬이 움직인 방향에서 -1 만큼 뒤로
# 움직인 방향은 어차피 dx, dy 참고하면 됨
# 빨간 구슬 성공 여부 체크
# 파란 구슬 성공 여부 체크
# 빨간 구슬만 성공 했을 경우 o
# 파란 구슬이 성공하거나 같이 들어올 경우 다른 경우 탐색

def getPos():
    rx, ry, bx, by = 0, 0, 0, 0

    for i in range(n):
        for j in range(m):
            if board[i][j] == 'R':
                rx = i
                ry = j
            elif board[i][j] == 'B':
                bx = i
                by = j

    return rx, ry, bx, by


def move(x, y, dx, dy):
    cnt = 0

    while True:

        nx = x + dx
        ny = y + dy

        if board[nx][ny] == '#':
            break

        x += dx
        y += dy
        cnt += 1

        if board[x][y] == 'O':
            break

    return x, y, cnt


def bfs():
    rx, ry, bx, by = getPos()
    q = deque()
    q.append((rx, ry, bx, by, 0)) # 마지막 0은 이동 횟수
    visited = set() # 조합 기준으로 방문 체크
    visited.add((rx, ry, bx, by))

    while q:
        rx, ry, bx, by, cnt = q.popleft()

        if cnt >= 10:
            return -1

        for i in range(4):
            nrx, nry, r_cnt = move(rx, ry, dx[i], dy[i])
            nbx, nby, b_cnt = move(bx, by, dx[i], dy[i])

            if board[nbx][nby] == 'O': # 파란 구슬이 빠지면 넘기기
                continue  
            elif board[nrx][nry] == 'O':
                return cnt + 1

            if nrx == nbx and nry == nby:
                if r_cnt > b_cnt: # 빨간 구슬이 파란 구슬보다 더 많이 움직인 경우 *더 뒤에 있었단 의미
                    nrx -= dx[i]
                    nry -= dy[i]
                elif r_cnt < b_cnt: # 파란 구슬이 더 많ㅇ느 경우
                    nbx -= dx[i]
                    nby -= dy[i]

            if (nrx, nry, nbx, nby) not in visited:
                visited.add((nrx, nry, nbx, nby))
                q.append((nrx, nry, nbx, nby, cnt + 1))

    return -1 # 어차피 못 들어가면 -1 임



print(bfs())
