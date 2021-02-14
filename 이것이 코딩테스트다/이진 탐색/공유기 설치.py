import sys
n, c = map(int, sys.stdin.readline().split())
arr = [0] * n
for i in range(n):
    arr[i] = int(sys.stdin.readline())
arr.sort()
start, end = 1, arr[-1] - arr[0]
answer = 0

while start <= end:
    mid = (start + end) // 2  # gap
    value = arr[0]
    cnt = 1
    for i in range(1, n):
        if arr[i] >= value + mid:
            value = arr[i]
            cnt += 1
        if cnt >= c:
            start = mid + 1
            answer = mid
            break
    if cnt < c:
        end = mid - 1

print(answer)
