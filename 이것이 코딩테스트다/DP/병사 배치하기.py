from bisect import bisect
n = int(input())
arr = list(map(int, input().split()))

# dp : O(N^2)
dp = [1] * n
for i in range(1,n):
    for j in range(i - 1, -1, -1):
        if arr[j] > arr[i] and dp[j] >= dp[i]:
            dp[i] = dp[j] + 1
print(n - max(dp))

# 이진 탐색 : O(NlogN)
arr.reverse()
lis = [arr[0]]
for i in range(1, n):
    if lis[-1] < arr[i]:
        lis.append(arr[i])
    elif lis[-1] > arr[i]:
        lis[bisect(lis, arr[i])] = arr[i]
print(n - len(lis))