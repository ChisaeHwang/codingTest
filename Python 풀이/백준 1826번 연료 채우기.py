import heapq

n = int(input())
oil = []
for _ in range(n):
    dist, fuel = map(int, input().split())
    oil.append((dist, fuel))

oil.sort()  # 거리 기준으로 정렬

destination, now_fuel = map(int, input().split())

cnt = 0
now_dist = 0
q = []
idx = 0  # 현재 확인 중인 주유소 인덱스

while True:
    now_dist += now_fuel  # 현재 연료 만큼 이동

    if destination <= now_dist:  # 현재 연료로 도착하면 종료
        break

    # 현재 거리 기준에서 도달할 수 있는 주유소의 연료량 넣기
    while idx < n and oil[idx][0] <= now_dist:
        heapq.heappush(q, -oil[idx][1])
        idx += 1
    
    if not q:  # 사용할 수 있는 주유소가 없으면 도착 불가
        print(-1)
        exit()
        
    now_fuel = -heapq.heappop(q)
    cnt += 1  # 주유소 방문 횟수 증가

print(cnt)