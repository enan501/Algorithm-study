answer, i = 0, 0
n = int(input())
fears = list(map(int, input().split()))
fears.sort()
while i < n:
    if i + fears[i] < n:
        i += (fears[i])
    answer += 1
print(answer)