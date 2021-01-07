s = list(map(int,input()))
answer = 0
cur = s[0]
for num in s[1:]:
    if cur != num:
        answer += 1
        cur = num
print(int((answer+1)/2))