n = int(input())
positive = []  # 양수
negative = []  # 음수
ones = 0       # 1의 개수
zeros = 0      # 0의 개수

# 숫자 분류
for _ in range(n):
    num = int(input())
    if num > 1:
        positive.append(num)
    elif num < 0:
        negative.append(num)
    elif num == 1:
        ones += 1
    else:  # num == 0
        zeros += 1

# 양수는 내림차순, 음수는 오름차순 정렬
positive.sort(reverse=True)  
negative.sort()           

result = ones  # 1은 그냥 더하기

# 양수 처리 (큰 수부터 곱하기)
for i in range(0, len(positive)-1, 2):
    result += positive[i] * positive[i+1]
if len(positive) % 2 == 1: # 마지막 원소 더하기
    result += positive[-1]

# 음수 처리 (작은 수부터 곱하기)
for i in range(0, len(negative)-1, 2):
    result += negative[i] * negative[i+1]
# 음수가 홀수 개이고 0이 없으면 마지막 원소 더하기 
# 0이 하나라도 있으면 마지막 원소는 그냥 없다고 봐도됨 (마지막 원소 x 0)
if len(negative) % 2 == 1 and zeros == 0:
    result += negative[-1]

print(result)