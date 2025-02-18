def check_server(cur_t, servers):
    active_cnt = 0
    for s_t, e_t in servers: # 현재 운영 중인 서버갯수 체크
        if s_t <= cur_t < e_t:
            active_cnt += 1
    return active_cnt

def solution(players, m, k):
    answer = 0
    
    servers = []
    # (시작시간, 종료시간) 형태로 저장
    
    for i in range(24):
        if players[i] >= m:
            active_server = check_server(i, servers)
            if (active_server + 1) * m <= players[i]: # 사용 서버보다 사용자수가 많을경우
                temp = (players[i] // m) - active_server
                for _ in range(temp):
                    servers.append((i, i + k))
                    answer += 1
    
    return answer