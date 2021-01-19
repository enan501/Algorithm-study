from itertools import product

def solution(n, build_frame):
    answer = []
    # arr[y][x] = -1 : 빈칸, 0 : 기둥, 1 : 보, 2 : 둘다
    arr = [[-1 for _ in range(n+1)] for _ in range(n+1)]
    for bf in build_frame:
        x,y, is_pillar = bf[0], bf[1], (bf[2] == 0)
        if bf[3] == 1:  # 생성
            if is_valid(x, y, is_pillar, arr):
                arr[y][x] += (1 if is_pillar else 2)
        else:  # 삭제
            arr[y][x] -= (1 if is_pillar else 2)
            check_list = product([-1,0,1], [0,1], [True, False])
            for dx, dy, dp in check_list:
                if ((dp and arr[y+dy][x+dx] % 2 == 0) or (not dp and arr[y+dy][x+dx] >= 1)) and not is_valid(x+dx, y+dy, dp, arr):
                    arr[y][x] += (1 if is_pillar else 2)
                    break
    for j in range(n+1):
        for i in range(n+1):
            if arr[i][j] % 2 == 0:
                answer.append([j, i, 0])
            if arr[i][j] >= 1:
                answer.append([j, i, 1])
    return answer

def is_valid(x, y, is_pillar, arr):
    if is_pillar:
        # 바닥, 기둥위, 보의 한쪽 끝
        if y == 0 or arr[y-1][x] % 2 == 0 or arr[y][x-1] >= 1 or arr[y][x] >= 1:
            return True
    else:
        # 한쪽 끝이 기둥 위, 양쪽 끝이 보와 연결
        if arr[y-1][x] % 2 == 0 or arr[y-1][x+1] % 2 == 0 or (arr[y][x-1] >= 1 and arr[y][x+1] >= 1):
            return True
    return False

n = 5
# build_frame = [[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]
build_frame = [[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,2,0,1]]


print(solution(n,build_frame))