import sys
n, m = map(int, sys.stdin.readline().split())
parents = list(map(int, sys.stdin.readline().split()))
children = [[] for _ in range(n)]
comps = [0] * n

for i, parent in enumerate(parents[1:]):
    children[parent-1].append(i+1)

for _ in range(m):
    i, w = map(int, sys.stdin.readline().split())
    comps[i-1] += w

for i, chs in enumerate(children):
    for ch in chs:
        comps[ch] += comps[i]

print(' '.join(map(str,comps)))