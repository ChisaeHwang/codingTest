import heapq
import sys
input = sys.stdin.readline

n = int(input())
classes = []

for _ in range(n):
    start, end = map(int, input().split())
    classes.append((start, end))
    # classes[i][0] = 강의 시작 시간
    # classes[i][1] = 강의 끝나는 시간

classes.sort(key=lambda x: x[0])


queue = []
heapq.heappush(queue, classes[0][1]) # 첫 강의 끝나는 시간 입력

for i in range(1, n):
    if queue[0] <= classes[i][0]: # 현재 강의실 끝나는 시간이 다음 강의 시작 시간보다 작거나 같으면
        heapq.heappop(queue) # 현재 강의실 끝나는 시간 제거
    heapq.heappush(queue, classes[i][1]) # 다음 강의 끝나는 시간 추가
    # 이때 굳이 카운팅이 필요하진 않음 어차피 기존 강의실 재사용하면
    # 힙 큐안에서 강의실 제거하고 다시 만들기 때문

print(len(queue))
