import sys
from math import ceil
from bisect import bisect

n = int(sys.stdin.readline())
cranes = sorted(list(map(int, sys.stdin.readline().split())), reverse=True)
m = int(sys.stdin.readline())
boxes = sorted(list(map(int, sys.stdin.readline().split())))
answer = ceil(m/n)
if cranes[0] < boxes[-1]:
    answer = -1
else:
    for i, crane in enumerate(cranes[1:]):
        answer = max(answer, ceil((m - bisect(boxes, crane)) / (i+1)))
print(answer)