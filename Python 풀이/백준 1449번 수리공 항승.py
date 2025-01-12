
n, m = map(int, input().split())
positions = list(map(int, input().split()))

positions.sort()

cnt = 1
tape = positions[0] - 0.5 + m  # 0.5 씩 간격을 줘야함
# 그러믈 만약 1이면 0.5 ~ 1.5 까지 테이프롤 붙여야함

for i in range(1, n):
    if positions[i] + 0.5 > tape:
        tape = positions[i] - 0.5 + m
        cnt += 1

print(cnt)