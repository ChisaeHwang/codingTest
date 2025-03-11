n = int(input())
k = int(input())

sensors = list(map(int, input().split()))

if n <= k: # 도로마다 센서가 있기에 0
    print(0)
else:
    sensors.sort()
    dist = []
    total = 0

    for i in range(1, n):
        total += sensors[i] - sensors[i - 1]
        dist.append(sensors[i] - sensors[i - 1])
    
    dist.sort(reverse=True) # 내림차순으로 정렬

    for i in range(k-1): # 그룹으로 나뉘니 그룹이 2개면 하나만 3개면 두개
        if i < k - 1:
            total -= dist[i]

    print(total)
