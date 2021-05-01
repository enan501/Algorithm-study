import sys
from collections import deque

n = int(sys.stdin.readline())
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
shark_size, eat_fish_cnt = 2, 0
shark_position = (-1, -1)
answer = 0
arr = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int, sys.stdin.readline().split()))
    for j in range(n):
        if arr[i][j] == 9:
            shark_position = (i, j)
            arr[i][j] = 0

while True:
    visit = [[False for _ in range(n)] for _ in range(n)]
    eatable_fishes = []
    q = deque()
    q.append((0, shark_position))

    while q:
        dist, (y, x) = q.popleft()
        if 0 < arr[y][x] < shark_size:
            eatable_fishes.append((dist, y, x))
        else:
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if 0 <= nx < n and 0 <= ny < n and arr[ny][nx] <= shark_size and not visit[ny][nx] and len(eatable_fishes) == 0:
                    visit[ny][nx] = True
                    q.append((dist + 1, (ny, nx)))

    if len(eatable_fishes) == 0:
        break
    else:
        d, y, x = min(eatable_fishes)
        shark_position = (y,x)
        arr[y][x] = 0
        answer += d
        eat_fish_cnt += 1
        if shark_size == eat_fish_cnt:
            shark_size += 1
            eat_fish_cnt = 0
print(answer)