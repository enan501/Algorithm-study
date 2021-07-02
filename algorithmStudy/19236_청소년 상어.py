import sys
from copy import deepcopy
dx, dy = [0, -1, -1, -1, 0, 1, 1, 1], [-1, -1, 0, 1, 1, 1, 0, -1]
arr = [[(0, 0) for _ in range(4)] for _ in range(4)]
fishes = [(0, 0, 0)] * 16
for i in range(4):
    temp = list(map(int, sys.stdin.readline().split()))
    for j in range(4):
        arr[i][j] = (temp[j * 2], temp[j * 2 + 1])
        fishes[temp[j * 2]] = (j, i, temp[j * 2 + 1])


def move_fish(arr, fishes):
    for i in range(len(fishes)):
        x, y, d = fishes[i]
        if d == -1:
            continue
        for j in range(8):
            nx, ny = x + dx[(d + j) % 8], y + dy[(d + j) % 8]
            if 0 <= nx < 4 and 0 <= ny < 4 and (nx, ny) != shark[:2]:
                ni = arr[ny][nx][0]
                fishes[i], fishes[ni] = fishes[ni], fishes[i]
                break


def move_shark(arr, fishes):
    narr = deepcopy(arr)
    nfishes = deepcopy(fishes)
    move_fish(narr, nfishes)
    res = 0
    x, y, d = shark
    for i in range(1,4):
        nx, ny = x + dx[d] * i, y + dy[d] * i
        if 0 <= nx < 4 and 0 <= ny < 4 and arr[ny][nx][0] != -1:
            res = max(res, move_shark(narr, nfishes) + arr[ny][nx][0])
    return res


shark = (0, 0, arr[0][0][1])
answer = arr[0][0][0]
arr[0][0] = (-1, -1)

while True:
    move_fish(arr,fishes)
