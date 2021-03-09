import sys
n = int(input())
m = int(input())
arr = [[sys.maxsize] * n for _ in range(n)]
for i in range(m):
    start, dst, cost = map(int, sys.stdin.readline().split())
    arr[start-1][dst-1] = min(arr[start-1][dst-1], cost)

for k in range(n):
    for i in range(n):
        for j in range(n):
            arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]) if i != j else 0

for i in range(n):
    print(' '.join(map(lambda x: str(x) if x != sys.maxsize else str(0), arr[i])))