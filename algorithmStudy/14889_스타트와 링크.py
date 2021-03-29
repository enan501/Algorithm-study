import sys
from itertools import combinations

n = int(sys.stdin.readline())
arr = [[]] * n
sum_total = 0
answer = int(1e9)
for i in range(n):
    arr[i] = list(map(int,sys.stdin.readline().split()))

team_list = combinations(range(n),n // 2)
for team_start in team_list:
    team_link = set(range(n)) - set(team_start)
    sum_start = 0
    for i, j in combinations(team_start, 2):
        sum_start += arr[i][j] + arr[j][i]
    for i, j in combinations(team_link, 2):
        sum_start -= arr[i][j] + arr[j][i]

    answer = min(answer, abs(sum_start))
print(answer)