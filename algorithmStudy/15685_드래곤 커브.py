import sys
n = int(sys.stdin.readline())
arr = [[False for _ in range(101)] for _ in range(101)]

dx, dy = [1, 0, -1, 0], [0, -1, 0, 1]
answer = 0

for _ in range(n):
    x, y, d, g = map(int, sys.stdin.readline().split())
    st = [d]
    arr[y][x] = True
    y += dy[d]
    x += dx[d]
    arr[y][x] = True
    for _ in range(g):
        for i in range(len(st)-1,-1,-1):
            d = (st[i] + 1) % 4
            st.append(d)
            y += dy[d]
            x += dx[d]
            arr[y][x] = True
for i in range(100):
    for j in range(100):
        if arr[i][j] and arr[i+1][j] and arr[i][j+1] and arr[i+1][j+1]:
            answer += 1
print(answer)

