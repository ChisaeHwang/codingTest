
n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

def get_distance(chicken, house):
    return abs(chicken[0] - house[0]) + abs(chicken[1] - house[1])

houses = []
chickens = []
selected_chickens = []
answer = float('inf')

for i in range(n):
    for j in range(n):
        if graph[i][j] == 1:
            houses.append((i, j))
        elif graph[i][j] == 2:
            chickens.append((i, j))



def get_distance():
    total = 0

    for house in houses:
        min_dist = float('inf')
        # 선택된 치킨 거리 최소값
        for chicken in selected_chickens:
            # 절대값 이용해서 거리 계산하기
            dist = abs(house[0] - chicken[0]) + abs(house[1] - chicken[1])
            min_dist = min(min_dist, dist)
        total += min_dist
    return total


def solve(start):
    global answer

    # 선택된 치킨이 m개면 거리 계산 후 최소값 매번 갱신
    if len(selected_chickens) == m:
        answer = min(answer, get_distance())
        return
    
    # 백트래킹 치킨 값 넣고 재귀 호출 후 뺴기
    for i in range(start, len(chickens)):
        selected_chickens.append(chickens[i])
        solve(i + 1)
        selected_chickens.pop()

solve(0)
print(answer)
