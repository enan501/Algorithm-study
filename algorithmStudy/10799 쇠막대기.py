arr = input()
answer, cnt = 0, 0
for i, a in enumerate(arr):
    if a == '(':
        cnt += 1
    else:
        cnt -= 1
        answer += (cnt if arr[i-1] == '(' else 1)
print(answer)