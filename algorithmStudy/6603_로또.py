import sys
from itertools import combinations
arr = []
while(True):
    arr = sys.stdin.readline().split()
    if arr[0] == '0':
        break
    for lotto in combinations(arr[1:], 6):
        print(' '.join(lotto))
    print()