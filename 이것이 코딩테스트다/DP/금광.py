t = int(input())
for _ in range(t):
    answer = 0
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    dp = [[0] * m for _ in range(n)]
    for i in range(n):
        dp[i][0] = arr[i * m]
    for j in range(1, m):
        for i in range(n):
            dp[i][j] = arr[i*m + j] + max(dp[i-1][j-1] if i > 0 else 0, dp[i][j-1], dp[i+1][j-1] if i+1 < n else 0)
    for i in range(n):
        answer = max(answer, dp[i][-1])
    print(answer)