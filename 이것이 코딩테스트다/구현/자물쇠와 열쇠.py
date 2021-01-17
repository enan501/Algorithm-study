import copy
def solution(key, lock):
    answer = False
    # 각 방향마다
    for r in range(0,4):
        for i in range(1-len(key), len(lock)):
            for j in range(1-len(key), len(lock)):
                if is_correct(key, lock, i, j):
                    return True
        key = rotate_90(key)
    return answer

def is_correct(key, lock, i, j):
    lock_temp = copy.deepcopy(lock)
    for ki in range(0, len(key)):
        for kj in range(0, len(key)):
            if 0 <= i+ki < len(lock) and 0 <= j+kj < len(lock):
                if key[ki][kj] == 1:
                    if lock_temp[i+ki][j+kj] == 1:
                        return False
                    else:
                        lock_temp[i+ki][j+kj] = 1
    for lock_w in lock_temp:
        for lock_value in lock_w:
            if lock_value == 0:
                return False
    return True

def rotate_90(m):
    n = len(m)
    ret = [[0] * n for _ in range(n)]
    for r in range(n):
        for c in range(n):
            ret[c][n-1-r] = m[r][c]
    return ret

key = [[0, 0, 0], [1, 0, 0], [0, 1, 1]]
lock = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
print(solution(key,lock))