from collections import deque

n = int(input())  # 보드 크기
k = int(input())  # 사과 개수

# 보드 초기화 (0: 빈칸, 1: 사과)
board = [[0] * n for _ in range(n)]


# 사과 위치 표시
for _ in range(k):
    a, b = map(int, input().split())
    board[a - 1][b - 1] = 1    


# 방향 변환 정보
l = int(input())
turns = {}
for _ in range(l):
    time, dire = input().split()

    turns[int(time)] = dire


# 방향 (동, 남, 서, 북)
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def simulate():
    # 뱀의 위치 (머리부터 꼬리까지)
    snake = deque([(0, 0)])
    d = 0  # 처음에는 동쪽
    time = 0
    
    while True:
        time += 1
        
        # 다음 머리 위치
        x, y = snake[-1]
        nx = x + dx[d]
        ny = y + dy[d]
   
        
        # 벽이나 자기자신과 부딪히면 종료
        if 0 > nx or nx >= n or 0 > ny or ny >= n or (nx, ny) in snake:
            return time

            
        # 머리를 다음 위치로 이동
        snake.append((nx, ny))
        
        # 사과가 없다면 꼬리 제거
        if board[nx][ny] != 1:
            snake.popleft()
        else:
            board[nx][ny] = 0
            
        
        # 방향 전환 확인 시뮬레이션에서 주로 사용
        if time in turns:
            if turns[time] == 'L': # 왼쪽으로
                d = (d - 1) % 4
            elif turns[time] == 'D':
                d = (d + 1) % 4

print(simulate())