from collections import deque

def bfs(M, N, H, box):
    queue = deque()
    unripe = 0  # 토마토가 모두다 익었는지 안 익었는지 판단하기 위한 용도
    
    # 초기 상태 설정
    for i in range(H):
        for j in range(N):
            for k in range(M):
                if box[i][j][k] == 1:
                    queue.append((i, j, k, 0))
                elif box[i][j][k] == 0:
                    unripe += 1  # 안 익은 토마토마다 카운트

    # 6방향 이동 (위, 아래, 왼쪽, 오른쪽, 앞, 뒤)
    directions = [(-1,0,0), (1,0,0), (0,-1,0), (0,1,0), (0,0,-1), (0,0,1)]

    days = 0
    while queue:
        h, r, c, day = queue.popleft()
        days = max(days, day)
        
        for dh, dr, dc in directions:
            nh = h + dh
            nr = r + dr
            nc = c + dc
            if 0 <= nh < H and 0 <= nr < N and 0 <= nc < M and box[nh][nr][nc] == 0:
                box[nh][nr][nc] = 1
                unripe -= 1  # 한 개씩 카운트 줄이기
                queue.append((nh, nr, nc, day + 1))

    # 결과 반환
    if unripe == 0:
        return days  # 모든 토마토가 익었을 때
    else:
        return -1  # 토마토가 모두 익지 못하는 상황

# 입력 처리
M, N, H = map(int, input().split())
box = [[list(map(int, input().split())) for _ in range(N)] for _ in range(H)] # 3차원

# 결과 계산 및 출력
result = bfs(M, N, H, box)
print(result)