n, m = map(int,input().split())
balls = list(map(int,input().split()))
weights = [0 for _ in range(0, m)]
answer = int(len(balls) * (len(balls)-1) / 2)
for ball in balls:
    weights[ball-1] += 1
for weight in weights:
    answer -= int(weight * (weight-1) / 2)
print(answer)