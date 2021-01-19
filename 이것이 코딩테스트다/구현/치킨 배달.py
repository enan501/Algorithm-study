from itertools import combinations
n, m = map(int,input().split())
houses, chickens = [], []
answer = 1999999999

for i in range(n):
    row = list(map(int, input().split()))
    for j in range(n):
        if row[j] == 1:
            houses.append((j, i))
        elif row[j] == 2:
            chickens.append((j, i))

for selected_chickens in combinations(chickens,m):
    chicken_dist = 0
    for house in houses:
        chicken_dist += min(list(map(lambda pos: abs(house[0] - pos[0]) + abs(house[1] - pos[1]), selected_chickens)))
    answer = min(answer, chicken_dist)
print(answer)