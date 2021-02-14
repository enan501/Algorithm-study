import sys
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
start, end = 0, len(arr) - 1
answer = -1

while start <= end:
    mid = (start + end) // 2
    if arr[mid] == mid:
        answer = mid
        break
    elif arr[mid] < mid:
        start = mid + 1
    else:
        end = mid

print(answer)