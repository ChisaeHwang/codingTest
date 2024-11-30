
n = int(input())
rural = list(map(int, input().split()))
budget = int(input())


def parametric_search():
    left = 0
    right = max(rural)

    while left <= right:
        mid = (left + right) // 2
        
        if is_possible(mid):
            answer = mid
            left = mid + 1
        else:
            right = mid - 1
    
    return answer


def is_possible(limit):
    sum = 0
    for i in range(n):
        sum += min(rural[i], limit)

    if sum <= budget:
        return True
    else:
        return False


answer = parametric_search()

if sum(rural) <= budget:
    print(max(rural))
else:
    print(answer)