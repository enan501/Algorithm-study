import sys
n, m, y, x, k = map(int, sys.stdin.readline().split())
dx, dy = [1, -1, 0, 0], [0, 0, -1, 1]
dice = [0, 0, 0, 0, 0, 0]
mv = [
    [3,0,2,5,5,3,0,2],  # 동   1
    [3,0,2,5,0,2,5,3],  # 서 3 0 2
    [1,0,4,5,0,4,5,1],  # 북   4
    [1,0,4,5,5,1,0,4]   # 남   5
]
arr = [[] for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int, sys.stdin.readline().split()))
dirs = list(map(int,sys.stdin.readline().split()))
for dir in dirs:
    if 0 <= x+dx[dir-1] < m and 0 <= y+dy[dir-1] < n:
        x += dx[dir-1]
        y += dy[dir-1]
        dice[mv[dir-1][0]], dice[mv[dir-1][1]], dice[mv[dir-1][2]], dice[mv[dir-1][3]]\
            = dice[mv[dir-1][4]], dice[mv[dir-1][5]], dice[mv[dir-1][6]], dice[mv[dir-1][7]]
        if arr[y][x] == 0:
            arr[y][x] = dice[5]
        else:
            dice[5] = arr[y][x]
            arr[y][x] = 0
        print(dice[0])
