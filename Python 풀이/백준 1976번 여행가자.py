def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

n = int(input()) 
m = int(input()) 

# 부모 테이블 초기화
parent = [i for i in range(n+1)]

# 도시 간의 연결 정보 입력 받기
for i in range(1, n+1):
    connections = list(map(int, input().split()))
    for j in range(n):
        if connections[j] == 1:  # 도시 i와 j+1이 연결되어 있다면
            union_parent(parent, i, j+1)

# 여행 계획 입력 받기
plan = list(map(int, input().split()))

# 여행 계획에 속한 모든 도시가 같은 집합에 속하는지 확인
result = True
root = find_parent(parent, plan[0])
for i in range(1, m):
    if find_parent(parent, plan[i]) != root:
        result = False
        break

print("YES" if result else "NO")