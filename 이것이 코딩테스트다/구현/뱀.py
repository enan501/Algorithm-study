def move(dir):
    if dir == 0:  # 상
        next_pos = (snake[0][0] - 1, snake[0][1])
    elif dir == 1:  # 우
        next_pos = (snake[0][0], snake[0][1] + 1)
    elif dir == 2:  # 하
        next_pos = (snake[0][0] + 1, snake[0][1])
    else:  # dir == 3 : 좌
        next_pos = (snake[0][0], snake[0][1] - 1)
    # 벽에 부딪히는지, 몸에 부딪히는지
    if next_pos[0] < 0 or next_pos[0] == n or next_pos[1] < 0 or next_pos[1] == n:
        return False
    for body in snake[2:]:
        if next_pos == body:
            return False
    snake.insert(0, next_pos)
    for apple in apples:
        if next_pos == apple:
            apples.remove(apple)
            return True
    snake.pop()
    return True

n = int(input())
k = int(input())
apples = []
for _ in range(k):
    ay,ax = map(int,input().split())
    apples.append((ay-1, ax-1))
l = int(input())
answer, a_index, dir = 0, 0, 1
actions = []
for _ in range(l):
    actions.append(input().split())
snake = [(0, 0)]
sec, next_dir = actions[a_index]
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

print(answer+1)

