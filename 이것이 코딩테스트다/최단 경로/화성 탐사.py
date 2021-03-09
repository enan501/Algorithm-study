import sys, heapq
t = int(input())
for _ in range(t):
    n = int(input())
    dist = [sys.maxsize] * n * n
    arr = [[] for _ in range(n)]
    for i in range(n):
        arr[i] = list(map(int, sys.stdin.readline().split()))

    dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
    hq = [(arr[0][0], 0, 0)]
    dist[0] = arr[0][0]
    while hq:
        d, cx, cy = heapq.heappop(hq)
        if dist[cy * n + cx] < d:
            continue
        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]
            if 0 <= nx < n and 0 <= ny < n and d + arr[ny][nx] < dist[ny * n + nx]:
                dist[ny * n + nx] = d + arr[ny][nx]
                heapq.heappush(hq, (dist[ny * n + nx], nx, ny))

    print(dist[-1])
