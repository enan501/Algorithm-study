n = int(input())
t, p, dp = [0] * n, [0] * n, [0] * (n + 1)
for i in range(n):
    t[i], p[i] = map(int,input().split())
for i in range(n-1, -1, -1):
    dp[i] = max(p[i] + dp[i+t[i]] if i+t[i] <= n else 0, dp[i+1])
print(dp[0])