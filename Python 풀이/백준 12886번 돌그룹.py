from collections import deque

a, b, c = map(int, input().split())
   
# 방문 체크를 위한 set
visited = set()
   
# BFS 함수
def bfs(a, b, c):
       # 총합 계산
       total = a + b + c
       
       # 총합이 3으로 나누어 떨어지지 않으면 불가능
       if total % 3 != 0:
           return 0
       
       # 이미 모든 그룹이 같으면 가능
       if a == b == c:
           return 1
       
       q = deque([(a, b, c)])
       visited.add((a, b, c))
       
       while q:
           a, b, c = q.popleft()
           
           # 모든 가능한 두 그룹 선택
           for x, y in [(a, b), (a, c), (b, c)]:
               if x == y:  # 크기가 같으면 건너뜀
                   continue
               
               # 작은 쪽, 큰 쪽 결정
               if x > y:
                   x, y = y, x
               
               # 새로운 상태 계산
               new_x = x + x
               new_y = y - x
               new_z = total - new_x - new_y
               
               # 새로운 상태 정렬 (순서 상관없음)
               new_state = tuple(sorted([new_x, new_y, new_z]))
               
               # 방문하지 않은 상태면 큐에 추가
               if new_state not in visited:
                   visited.add(new_state)
                   q.append(new_state)
                   
                   # 목표 상태에 도달했는지 확인
                   if new_x == new_y == new_z:
                       return 1
       
       # 모든 상태를 탐색해도 목표에 도달하지 못함
       return 0


print(bfs(a, b, c))


