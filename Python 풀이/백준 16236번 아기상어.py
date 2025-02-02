from collections import deque
import heapq

# 입력 받기
n = int(input())

board = [list(map(int, input().split())) for _ in range(n)]
# 입력 받는 배열일 경우

arr = [[False] * n for _ in range(n)]
# 입력 받지 않는 배열일 경우

sx = 0
sy = 0
# 초기 상어 위치 찾기
for i in range(n):
    for j in range(n):
        if board[i][j] == 9:
            sx = i
            sy = j
            board[i][j] = 0

# 상어 초기 상태
s_size = 2
eat_count = 0
time = 0


# 방향 설정 (상좌우하)
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]


# BFS로 먹을 수 있는 물고기 찾는 함수
def find_fish():
    # 방문 배열 초기화
    visited = [[False] * n for _ in range(n)]
    
    # 먹을 수 있는 물고기 저장할 우선순위 큐 (거리, x, y)
    eat = []

    # BFS 큐 초기화 (상어 위치부터 시작)
    q = deque()
    q.append((sx, sy, 0))
    visited[sx][sy] = True

    # BFS 탐색
    while q:
        # 현재 위치에서 4방향 확인
        x, y, dist = q.popleft()
        
        # 갈 수 있는 곳인지 체크 (크기 체크)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] \
                and board[nx][ny] <= s_size:
                
                visited[nx][ny] = True
                # 먹을 수 있는 물고기면 우선순위 큐에 추가
                if 0 < board[nx][ny] < s_size:
                    heapq.heappush(eat, (dist+1, nx, ny))

                # 지나갈 수 있으면 큐에 추가
                q.append((nx, ny, dist+1))


    # 먹을 수 있는 물고기 목록 반환
    return eat

# 시뮬레이션 시작
while True:
    # 먹을 수 있는 물고기 찾기
    fish = find_fish()
    
    # 더 이상 먹을 물고기 없으면 종료
    if not fish:
        break

    # 가장 우선순위 높은 물고기 먹기
    dist, nx, ny = heapq.heappop(fish)
    eat_count += 1
    board[nx][ny] = 0

    # 상어 위치 이동
    sx = nx
    sy = ny

    # 시간 증가
    time += dist

    # 상어 크기 증가 체크
    if s_size == eat_count:
        eat_count = 0
        s_size += 1

# 결과 출력
print(time)