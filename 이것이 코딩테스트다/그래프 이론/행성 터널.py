import sys

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


n = int(sys.stdin.readline())
parent = [i for i in range(n)]
xs, ys, zs = [()] * n, [()] * n, [()] * n
edges = []
cost = 0
for i in range(n):
    xs[i], ys[i], zs[i] = map(lambda pos: (int(pos), i), sys.stdin.readline().split())
xs.sort()
ys.sort()
zs.sort()

for i in range(1, n):
    edges.append((xs[i][0] - xs[i-1][0], xs[i-1][1], xs[i][1]))
    edges.append((ys[i][0] - ys[i-1][0], ys[i-1][1], ys[i][1]))
    edges.append((zs[i][0] - zs[i-1][0], zs[i-1][1], zs[i][1]))

edges.sort()

for dist, x, y in edges:
    if find(parent, x) != find(parent, y):
        union(parent, x, y)
        cost += dist

print(cost)
