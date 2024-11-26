from math import ceil

H, W, N, M = map(int, input().split())

Hn = ceil(H/(N + 1))
Wn = ceil(W/(M + 1))

print(Hn * Wn)  
