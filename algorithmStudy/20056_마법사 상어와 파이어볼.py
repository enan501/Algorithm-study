import sys

n, m, k = map(int, sys.stdin.readline().split())
arr = [[[] for _ in range(n)] for _ in range(n)]
dx, dy = [0, 1, 1, 1, 0, -1, -1, -1], [-1, -1, 0, 1, 1, 1, 0, -1]
for i in range(m):
    ri, ci, mi, si, di = map(int, sys.stdin.readline().split())
    arr[ri-1][ci-1].append((mi, si, di))

for t in range(k):
    temp = [[[] for _ in range(n)] for _ in range(n)]
    # 이동
    for i in range(n):
        for j in range(n):
            for fireball in arr[i][j]:
                temp[(i + dy[fireball[2]] * fireball[1]) % n][(j + dx[fireball[2]] * fireball[1]) % n].append(fireball)
            arr[i][j].clear()
    # 합치고 나누기
    for i in range(n):
        for j in range(n):
            ball_cnt = len(temp[i][j])
            if ball_cnt == 1:
                arr[i][j] = temp[i][j]
            elif ball_cnt >= 2:
                total_mass, total_speed = 0, 0
                even_dir, odd_dir = 0, 0
                for fireball in temp[i][j]:
                    total_mass += fireball[0]
                    total_speed += fireball[1]
                    if fireball[2] % 2 == 0:
                        even_dir += 1
                    else:
                        odd_dir += 1
                if total_mass // 5 > 0:
                    dirs = [1,3,5,7] if even_dir > 0 and odd_dir > 0 else [0,2,4,6]
                    arr[i][j] = [(total_mass//5, total_speed//ball_cnt, d) for d in dirs]

answer = 0
for i in range(n):
    for j in range(n):
        answer += sum((map(lambda x: x[0], arr[i][j])))
print(answer)