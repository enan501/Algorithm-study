import sys

def find(parent,x):
        if parent[x] != x:
            parent[x] = find(parent, parent[x])
        return parent[x]

def union(parent,a,b):
    a = find(parent, a)
    b = find(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


n, m = map(int, sys.stdin.readline().split())
parent = [i for i in range(n)]
edges = []
cost = 0

for _ in range(m):
    x, y, dist = map(int, sys.stdin.readline().split())
    edges.append((dist, x, y))
    cost += dist
edges.sort()

for dist, x, y in edges:
    if find(parent, x) != find(parent, y):
        union(parent, x, y)
        cost -= dist

print(cost)

