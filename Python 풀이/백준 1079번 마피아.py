def solve():
    N = int(input())
    guilt_scores = list(map(int, input().split()))
    R = []
    for _ in range(N):
        row = list(map(int, input().split()))
        R.append(row)
    eunjin_idx = int(input())
    
    def simulate_game(alive, scores, is_night):
        # 은진이가 살아있는지 확인
        if eunjin_idx not in alive:
            return 0
        
        # 은진이만 남았으면 게임 종료
        if len(alive) == 1:
            return 0
        
        if is_night:  # 밤
            max_result = 0
            
            # 은진이를 제외한 모든 살아있는 참가자에 대해 시도
            for target in alive:
                if target == eunjin_idx:
                    continue
                
                # target을 죽이고 유죄 지수 갱신
                new_alive = alive.copy()
                new_alive.remove(target)
                
                new_scores = scores.copy()
                for person in new_alive:
                    new_scores[person] += R[target][person]
                
                # 낮 실행
                result = 1 + simulate_game(new_alive, new_scores, False)
                max_result = max(max_result, result)
            
            return max_result
        
        else:  # 낮
            max_guilt = -1
            victim = -1
            
            for person in alive:
                if scores[person] > max_guilt or (scores[person] == max_guilt and person < victim):
                    max_guilt = scores[person]
                    victim = person
            
            # 희생자 제거
            new_alive = alive.copy()
            new_alive.remove(victim)
            
            # 은진이가 죽었으면 게임 종료
            if victim == eunjin_idx:
                return 0
            
            # 밤 실행
            result = simulate_game(new_alive, scores, True)
            
            return result
    

    initial_alive = set(range(N))
    
    is_night_first = (N % 2 == 0)
    
    result = simulate_game(initial_alive, guilt_scores, is_night_first)
    return result

print(solve())