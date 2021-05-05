from collections import deque

n, t, g = map(int,input().split())
arr = [int(1e9)] * 100000
answer = int(1e9)

q = deque()
q.append((n,0))
while q:
    num, cnt = q.popleft()
    if cnt > t or arr[num] <= cnt:
        continue
    arr[num] = cnt
    if num == g:
        answer = min(answer, cnt)
        continue
    if num < 99999:
        q.append((num + 1, cnt + 1))
    if num > 0 and num * 2 <= 99999:
        b_li = list(str(num * 2))
        b = int(str(int(b_li[0]) - 1) + ''.join(b_li[1:])) if num >= 5 else num * 2 - 1
        q.append((b, cnt + 1))
print(answer if answer != int(1e9) else "ANG")




