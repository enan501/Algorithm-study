answer, count = 0, 0
n = int(input())
fears = list(map(int, input().split()))
fears.sort()
for fear in fears:
    count += 1
    if count > fear:
        answer += 1
        count = 0
print(answer)
