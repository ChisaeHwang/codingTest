from collections import deque

def solution(land):
    answer = 0
    
    n = len(land)
    m = len(land[0])
    
    visited = [[0] * m for _ in range(n)]
    
    dx = [0, 1, -1, 0]
    dy = [1, 0, 0, -1]
    
    def bfs(sx, sy, visited, land, group_num):
        
        ret = 0
        cols = set() # 수직으로(열)만 탐색하기에 열만 저장하면 됨 
        
        q = deque()
        q.append((sx, sy))
        visited[sx][sy] = group_num
        
        while q:
            x, y = q.popleft()
            ret += 1
            cols.add(y)
            
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < n and 0 <= ny < m:
                    if land[nx][ny] != 0 and not visited[nx][ny]:
                        visited[nx][ny] = group_num
                        q.append((nx, ny))
              

        return ret, cols
    
    
    group_num = 1
    group_info = {}
    
    for i in range(n):
        for j in range(m):
            if land[i][j] == 1 and not visited[i][j]:
                ret, cols = bfs(i, j, visited, land, group_num)
                group_info[group_num] = (ret, cols)
                group_num += 1
    
    for j in range(m):
        temp = set()  # 현재 열에 있는 그룹 번호들
        for i in range(n):
            if visited[i][j] != 0:
                temp.add(visited[i][j])
        
        ret = 0
        for num in temp:
            ret += group_info[num][0]  # group_info[그룹번호][0]은 해당 그룹의 크기
            
        answer = max(answer, ret)  # 최대값 갱신
    
    return answer