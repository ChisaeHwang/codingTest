
n, x = map(int, input().split())
visitors = list(map(int, input().split()))

def sliding_window(arr, k):
    max_sum = sum(arr[:k])
    temp_sum = max_sum
    max_cnt = 1

    for i in range(k, len(arr)):
        max_sum = max_sum + arr[i] - arr[i-k]
        if max_sum > temp_sum:
            max_cnt = 1
        elif max_sum == temp_sum:
            max_cnt += 1
        temp_sum = max(temp_sum, max_sum)

    return temp_sum, max_cnt

max_sum, max_cnt = sliding_window(visitors, x)

if max_sum == 0:
    print("SAD")
else:
    print(max_sum)
    print(max_cnt)

