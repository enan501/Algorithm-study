import sys
n, m = map(int, input().split())
arr = [[False] * n for _ in range(n)]
for i in range(m):
    start, dst = map(int, sys.stdin.readline().split())
    arr[start - 1][dst - 1] = True

for k in range(n):
    for i in range(n):
        for j in range(n):
            if i != j and arr[i][k] and arr[k][j]:
                arr[i][j] = True

answer = 0
for i in range(n):
    cnt = 0
    for j in range(n):
        if arr[i][j] or arr[j][i] or i == j:
            cnt += 1
        else:
            break
    if cnt == n:
        answer += 1

print(answer)