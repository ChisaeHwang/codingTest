
n, m = map(int, input().split())

min_package = 1001
min_single = 1001

for _ in range(m):
    package, single = map(int, input().split())
    min_package = min(min_package, package)
    min_single = min(min_single, single)

ret = 0

# 6개 단위로 처리
six_line = n // 6 # 6개로 나눈 값
remain_line = n % 6 # 나머지

# 6개 단위 처리
if min_package <= min_single * 6:
    ret += six_line * min_package
else:
    ret += six_line * (min_single * 6)

# 나머지 처리
if min_package <= min_single * remain_line:
    ret += min_package
else:
    ret += min_single * remain_line

print(ret)