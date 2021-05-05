from collections import deque
dx, dy = [-1,0,1,0], [0,-1,0,1]

def cur_cost(cur_dir, next_dir):
    if cur_dir == next_dir % 2 :
        return 100
    else:
        return 600

def solution(board):
    answer = 0
    n = len(board)
    dp = [[[int(1e9), int(1e9)] for _ in range(n)] for _ in range(n)]
    dp[0][0] = [0,0]
    q = deque()
    q.extend([(0,0,0), (0,0,1)]) # x, y, d (가로=0, 세로=1)
    while q:
        x, y, d = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            total_cost = dp[y][x][d] + cur_cost(d, i)
            if 0<=nx<n and 0<=ny<n and board[ny][nx] == 0 and dp[ny][nx][i%2] > total_cost:
                dp[ny][nx][i % 2] = total_cost
                q.append((nx,ny,i % 2))
    answer = min(dp[n-1][n-1][0], dp[n-1][n-1][1])
    return answer


board = [[0, 0, 1, 0], [0, 0, 0, 0], [0, 1, 0, 1], [1, 0, 0, 0]]
print(solution(board))