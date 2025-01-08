n = int(input())
alpha = {}


for _ in range (n):
    word = input()

    # 각 알파벳의 가중치를 얻기 위함
    # 알파벳이 여러개 있을 수 있기에 각 알파벳의 가중치를 집계하고
    # 그 값을 토대로 가중치가 큰 순서대로 9 -> 1까지 입력
    for i, char in enumerate(word[::-1]):
        # 가중치 입력을 위해서 뒤에서 부터 순회
        # enumerate는 인덱스 넘버도 반환해줌
        if char not in alpha:
            alpha[char] = 0
        alpha[char] += 10 ** i
        # 가중치 입력은 제곱 ** 활용


temp_alpha = sorted(alpha.items(), key=lambda x: x[1], reverse = True)

num = 9
ret = 0

# 내림차순으로 정렬하기에 가줓이 큰수부터 순회
for alpha, weight in temp_alpha:
    ret += weight * num
    num = num - 1

print(ret)