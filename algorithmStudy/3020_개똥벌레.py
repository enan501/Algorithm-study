import sys
from bisect import bisect
n, h = map(int, sys.stdin.readline().split())
cave = [[0 for _ in range(n//2)] for _ in range(2)]
for i in range(n):
    cave[i%2][i//2] = int(sys.stdin.readline())
cave[0].sort()
cave[1].sort()
answer = int(1e9)
cnt = 0
for i in range(h):
    b = n - bisect(cave[0], i) - bisect(cave[1], h-1-i)
    if answer > b:
        cnt = 1
        answer = b
    elif answer == b:
        cnt += 1
print(f"{answer} {cnt}")