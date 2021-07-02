
def solution(n, results):
    answer = 0
    arr = [[False for _ in range(n)] for _ in range(n)]
    for fr, to in results:
        arr[fr-1][to-1] = True
    for i in range(n):
        arr[i][i] = True

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if i != j and arr[i][k] and arr[k][j]:
                    arr[i][j] = True

    for i in range(n):
        cnt = 0
        for j in range(n):
            if arr[i][j] or arr[j][i]:
                cnt += 1
            else:
                break
        if cnt == n:
            answer += 1
    return answer

n, result = 5, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]
print(solution(n, result))
