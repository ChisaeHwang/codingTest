def check(cur, que):
    strike = 0
    ball = 0

    for i in range(3):
        if cur[i] == que[i]:
            strike += 1
        elif cur[i] in que:
            ball += 1

    return strike, ball


n = int(input())
quest = []
for _ in range(n):
    num, s, b = map(int, input().split())
    num = list(map(int, str(num)))
    quest.append((num, s, b))

ans = 0
for i in range(1, 10):
    for j in range(1, 10):
        for k in range(1, 10):

            if i == j or j == k or i == k: # 중복 제거
                continue
            
            cur = [i, j, k]
            valid = True

            for num, s, b in quest: # 모든 질문에 대해서 통과해야함
                strike, ball = check(cur, num)
                if strike != s or ball != b:
                    valid = False
                    break
                
                # 3 2 4의 경우
                # 123 1s 1b
                # 356 1s 0b
                # 327 2s 0b
                # 489 0s 1b 다 통과함

            if valid:
                ans += 1

print(ans)
            