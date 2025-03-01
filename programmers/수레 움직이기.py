from collections import deque
import copy

def solution(maze):
    n, m = len(maze), len(maze[0])
    
    srx, sry = 0, 0  # 빨간 수레 시작
    sbx, sby = 0, 0  # 파란 수레 시작
    
    for i in range(n):
        for j in range(m):
            if maze[i][j] == 1:
                srx, sry = i, j
            elif maze[i][j] == 2:
                sbx, sby = i, j
    
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    visited_red = [[False] * m for _ in range(n)]
    visited_blue = [[False] * m for _ in range(n)]
    
    q = deque()
    # 빨간수레 위치, 파란수레 위치, 빨간방문배열, 파란방문배열, 이동횟수
    q.append((srx, sry, sbx, sby, visited_red, visited_blue, 0))
    
    while q:
        rx, ry, bx, by, prev_vr, prev_vb, count = q.popleft()
        
        vr = copy.deepcopy(prev_vr)
        vb = copy.deepcopy(prev_vb)
        vr[rx][ry] = True
        vb[bx][by] = True
        
        # 둘 다 도착
        if maze[rx][ry] == 3 and maze[bx][by] == 4:
            return count
            
        # 도착 여부 체크
        red_arrived = (maze[rx][ry] == 3)
        blue_arrived = (maze[bx][by] == 4)
        
        for i in range(4):
            # 파란 수레가 도착한 경우 -> 빨간 수레만 이동
            if blue_arrived:
                nrx, nry = rx + dx[i], ry + dy[i]
                if 0 <= nrx < n and 0 <= nry < m: 
                    if not (maze[nrx][nry] == 5 or vr[nrx][nry] or (nrx == bx and nry == by)):
                        q.append((nrx, nry, bx, by, vr, vb, count + 1))
                        
            # 빨간 수레가 도착한 경우 -> 파란 수레만 이동
            elif red_arrived:
                nbx, nby = bx + dx[i], by + dy[i]
                if 0 <= nbx < n and 0 <= nby < m:  
                    if not (maze[nbx][nby] == 5 or vb[nbx][nby] or (nbx == rx and nby == ry)):
                        q.append((rx, ry, nbx, nby, vr, vb, count + 1))
                        
            # 둘 다 도착하지 않은 경우 -> 둘 다 이동
            else:
                nrx, nry = rx + dx[i], ry + dy[i]
                if 0 <= nrx < n and 0 <= nry < m and not (maze[nrx][nry] == 5 or vr[nrx][nry]):
                    for j in range(4):
                        nbx, nby = bx + dx[j], by + dy[j]
                        if 0 <= nbx < n and 0 <= nby < m:  # 범위 체크
                            # 겹치거나 자리 바꾸는 경우 제외
                            if not (maze[nbx][nby] == 5 or vb[nbx][nby] or 
                                  (nrx == nbx and nry == nby) or 
                                  (nrx == bx and nry == by and nbx == rx and nby == ry)):
                                q.append((nrx, nry, nbx, nby, vr, vb, count + 1))
    
    return 0