def solution(n, w, num):
    
    board = [[0] * w for _ in range(100)]
    
    cnt = 1
    h = 0    # 현재 높이
    nw = 0   # 현재 가로 위치
    nx = 0   # num의 가로 위치
    nh = 0   # num의 높이
    direction = 1  # 1: 오른쪽, -1: 왼쪽
     
    while cnt <= n:
        board[h][nw] = cnt
        
        if cnt == num:
            nx = nw
            nh = h
            
        cnt += 1
        
        # 가로 위치 이동
        nw += direction
        
         # 한 줄이 다 찼거나 끝에 도달했을 때
        if nw >= w or nw < 0 or board[h][nw] != 0:
            h += 1  # 다음 층
            direction *= -1  # 방향 전환
            if direction == -1: # 오른쪽 벽 끝에 갈 경우
                nw = w - 1
            else: # 왼쪽 벽 끝에 갈 경우
                nw = 0
            
        if cnt > n:
            break
    
    
    answer = 1
    for i in range(nh + 1, 100):
        if board[i][nx] != 0:
            answer += 1
    
    return answer