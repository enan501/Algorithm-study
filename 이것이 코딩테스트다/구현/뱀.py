n = int(input())
k = int(input())

# apple 위치 저장
apples = []
for _ in range(k):
    ay,ax = map(int,input().split())
    apples.append((ay-1, ax-1))

# actions 저장
l = int(input())
actions = []
for _ in range(l):
    actions.append(input().split())

# 변수 세팅
dy, dx = [-1, 0, 1, 0], [0, 1, 0, -1] # 상 우 하 좌
snake = [(0, 0)]
answer, a_index, dir = 1, 0, 1 # a_index : 몇 번째 행동인지, dir : 방향
sec, next_dir = actions[a_index]

# 이동 가능한지 체크하고 이동
def move(dir):
    next_pos = (snake[0][0] + dy[dir], snake[0][1] + dx[dir])
    # 벽에 부딪히는지
    if next_pos[0] < 0 or next_pos[0] == n or next_pos[1] < 0 or next_pos[1] == n:
        return False
    for body in snake[2:]: # 몸에 부딪히는지
        if next_pos == body:
            return False
    snake.insert(0, next_pos)
    for apple in apples:
        if next_pos == apple:
            apples.remove(apple)
            return True
    snake.pop()
    return True

while move(dir):
    answer += 1
    if answer == int(sec):
        if next_dir == "L":
            dir = (dir + 3) % 4
        else:
            dir = (dir + 1) % 4
        a_index += 1
        if a_index < len(actions):
            sec, next_dir = actions[a_index]

print(answer)