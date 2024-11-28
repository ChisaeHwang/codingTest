
T = int(input())

for _ in range(T):
    numbers = list(map(int, input().split()))
    case_num = numbers[0]
    heights = numbers[1:]

    cnt = 0

    for i in range(20):
        for j in range(i):
            if heights[i] < heights[j]:
                cnt += 1  

    print(case_num, cnt)


