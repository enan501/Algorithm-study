import sys

dx, dy = [-1,1,0,0], [0,0,-1,1]
n,m = map(int,sys.stdin.readline().split())
blue_pos, red_pos = (-1,-1), (-1,-1)
arr = []


def move(cnt, dir, cur_red_pos, cur_blue_pos):
    answer = int(1e9)
    if cnt == 11:
        return int(1e9)
    elif cnt == 0:
        next_red_pos, next_blue_pos = cur_red_pos, cur_blue_pos
    else:
        next_blue_pos = getNextPosition(cur_blue_pos, cur_red_pos, dir)
        next_red_pos = getNextPosition(cur_red_pos, cur_blue_pos, dir)
        if next_blue_pos == (-1,-1):
            return int(1e9)
        elif next_red_pos == (-1,-1):
            return cnt
    for i in range(4):
        answer = min(answer, move(cnt + 1, i,next_red_pos, next_blue_pos))
    return answer


def getNextPosition(pos, other_pos, dir):
    x, y = pos
    is_same_line = False
    while arr[y][x] != '#':
        if (x, y) == other_pos:
            is_same_line = True
        if arr[y][x] == 'O':
            return -1, -1
        x += dx[dir]
        y += dy[dir]

    if is_same_line:
        x -= dx[dir]
        y -= dy[dir]
    return x - dx[dir], y - dy[dir]


for i in range(n):
    arr.append(list(sys.stdin.readline())[:-1])
    for j in range(len(arr[i])):
        if arr[i][j] == 'B':
            blue_pos = (j, i)
        elif arr[i][j] == 'R':
            red_pos = (j, i)
answer = move(0,0,red_pos,blue_pos)
print(answer if answer != int(1e9) else -1)
