def solution(m, n, puddles):
    arr = [[0 for _ in range(m)] for _ in range(n)]
    for px, py in puddles:
        arr[py-1][px-1] = -1
    arr[0][0] = 1
    for i in range(n):
        for j in range(m):
            if arr[i][j] != -1:
                if j >= 0 and arr[i][j-1] != -1:
                    arr[i][j] += arr[i][j-1]
                if i >= 0 and arr[i-1][j] != -1:
                    arr[i][j] += arr[i-1][j]
    answer = arr[n-1][m-1] % 1000000007
    return answer