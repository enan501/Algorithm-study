import sys, bisect
n, x = map(int, sys.stdin.readline().split())
arr = sorted(list(map(int, sys.stdin.readline().split())))
print(bisect.bisect(arr,x) - bisect.bisect(arr,x-1))