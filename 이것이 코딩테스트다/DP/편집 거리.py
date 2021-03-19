origin = input()
dst = input()
dp = [[0] * (len(dst) + 1) for _ in range(len(origin) + 1)]

for i in range(1, len(origin)+1):
    for j in range(1, len(dst)+1):
        dp[i][j] = dp[i-1][j-1] + 1 if origin[i-1] == dst[j-1] else max(dp[i][j-1], dp[i-1][j])

