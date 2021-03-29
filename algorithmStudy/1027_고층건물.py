import sys
n = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().split()))
building_views = [0] * n
for i in range(n):
    grad = -int(1e9)
    for j in range(i+1,n):
        if arr[j] > grad * (j-i) + arr[i]:
            grad = (arr[j] - arr[i]) / (j - i)
            building_views[i] += 1
            building_views[j] += 1

print(max(building_views))

# grad = highest - arr[i] / j - i
# y = grad * x + a
# a = arr[i] - grad * i
# y = grad * (j - i) + arr[i]