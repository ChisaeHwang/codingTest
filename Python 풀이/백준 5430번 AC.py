from collections import deque
import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    p = input().strip()
    n = int(input())
    arr = input().rstrip()[1:-1]
    
    if arr:
        arr = deque(map(int, arr.split(',')))
    else:
        arr = deque()
    
    is_reversed = False  # 뒤집힌 상태 관리
    error = False
    
    for cmd in p:
        if cmd == 'R':
            is_reversed = not is_reversed  # 상태만 변경
        else:  # cmd == 'D'
            if not arr:  # 빈 배열인 경우
                error = True
                break
            if is_reversed:
                arr.pop()  # 뒤집힌 상태면 뒤에서 제거
            else:
                arr.popleft()  # 아니면 앞에서 제거
    
    if error:
        print("error")
    else:
        if is_reversed:
            arr.reverse()  # 마지막에 한 번만 뒤집기
        print("[" + ",".join(map(str, arr)) + "]")



