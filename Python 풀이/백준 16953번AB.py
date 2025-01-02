
A, B = map(int, input().split())

cnt = 1;

while B > A:
    if B % 2 == 0:
        B = B // 2
    elif B % 10 == 1:
        B = B // 10
    else:  # 위 두 경우가 아니면 만들 수 없음
        break
    cnt += 1

if B == A:
    print(cnt)
else:
    print(-1)