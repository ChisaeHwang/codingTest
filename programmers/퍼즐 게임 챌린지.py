def solution(diffs, times, limit):
    answer = float('inf')
    
    left = 1
    right = max(diffs)
    
    print(right)
    
    while left <= right:
        
        mid = (left + right) // 2 # 정수형 나누기
        
        Flag = True
        cnt = 0
        
        for i in range(len(diffs)):
            # 레벨이 더 크거나 같은 경우 
            if diffs[i] <= mid:
                cnt += times[i]
            else: # 레벨이 더 작은 경우
                remain_level = 0
                if i != 0 :
                    remain_level = diffs[i] - mid
                cnt += times[i] + (times[i] + times[i - 1]) * remain_level
                
        # limit을 넘지 않을 경우, 레벨을 줄여도 됨, right 줄이기
        if cnt <= limit:
            answer = min(answer, mid)
            right = mid - 1
        else:
            left = mid + 1
            
    
    print(answer)
    
    return answer