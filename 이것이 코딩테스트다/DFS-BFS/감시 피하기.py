from itertools import combinations

def check():
    for tx, ty in teachers:
        for i in range(4):
            nx, ny = tx + dx[i], ty + dy[i]
            while 0 <= nx < n and 0 <= ny < n and arr[ny][nx] != 'O':
                if arr[ny][nx] == 'S':
                    return False
                nx += dx[i]
                ny += dy[i]

    return True

answer = "NO"
n = int(input())
arr = [[] for _ in range(n)]
teachers, spaces = [], []
dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
for i in range(n):
    arr[i] = input().split()
    for j in range(n):
        if arr[i][j] == 'T':
            teachers.append((j, i))
        elif arr[i][j] == 'X':
            spaces.append((j, i))


for f, s, t in combinations(spaces,3):
    arr[f[1]][f[0]], arr[s[1]][s[0]], arr[t[1]][t[0]] = 'O', 'O', 'O'
    if check():
        answer = "YES"
        break
    arr[f[1]][f[0]], arr[s[1]][s[0]], arr[t[1]][t[0]] = 'X', 'X', 'X'
print(answer)

