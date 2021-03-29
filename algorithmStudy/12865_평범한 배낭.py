import sys
n, k = map(int, sys.stdin.readline().split())
weights, values = [0] * n , [0] * n

for i in range(n):
    weights[i], values[i] = map(int, sys.stdin.readline().split())

# dp[i][j] = i번째 물건까지 고려해서 무게 j까지 담을 수 있는 최대값
# dp[i][j] = i번째 물건을 안 담는 경우 dp[i-1][j], 담는 경우 dp[i-1][j - 무게] + 가치
dp = [[0 for _ in range(k+1)] for _ in range(n)]
for i in range(n):
    for j in range(k+1):
        dp[i][j] = max(dp[i-1][j] if i>= 1 else 0, dp[i-1][j-weights[i]] + values[i] if j>=weights[i] else 0)

print(dp[n-1][k])