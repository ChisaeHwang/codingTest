def solution(n, q, ans):
       
    def check(cur_nums):
        
        # q[0]:1 2 3 4 5 | cur:3 4 7 9 10 -> 2
        
        for nums, a in zip(q, ans):
            temp = 0
            for num in cur_nums: # 현재 숫자
                if num in nums:
                    temp += 1
                    
            if temp != a:
                return False
            
        return True
    
    ret = []
    
    for i in range(1, n - 3):
        for j in range(i + 1, n - 2):
            for k in range(j + 1, n - 1):
                for l in range(k + 1, n):
                    for m in range(l + 1, n + 1):
                        nums = [i, j, k, l, m]
                        if check(nums):
                            ret.append(nums)
    
    return len(ret)