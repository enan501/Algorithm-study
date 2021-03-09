import sys, heapq
n, m = map(int,sys.stdin.readline().split())
arr = [[] for _ in range(n)]
dist = [(sys.maxsize, i) for i in range(n)]
for i in range(m):
    a, b = map(int,sys.stdin.readline().split())
    arr[a-1].append(b-1)
    arr[b-1].append(a-1)

dist[0] = (0, 0)
hq = [dist[0]]

while hq:
    d, i = heapq.heappop(hq)
    if d > dist[i][0]:
        continue
    for next in arr[i]:
        if dist[next][0] > d + 1:
            dist[next] = (d + 1, next)
            heapq.heappush(hq, dist[next])

dist.sort(key= lambda x: (-x[0],x[1]))
cnt = 0
for i in range(n):
    if dist[i][0] == dist[0][0]:
        cnt += 1
    else:
        break
print(f"{dist[0][1] + 1} {dist[0][0]} {cnt}")
