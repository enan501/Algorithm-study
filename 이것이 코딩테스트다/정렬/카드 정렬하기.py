import heapq, sys

n = int(input())
arr = [0] * n
for i in range(n):
    arr[i] = int(sys.stdin.readline())
heapq.heapify(arr)

answer = 0
while len(arr) > 1:
    sum_cost = heapq.heappop(arr) + heapq.heappop(arr)
    answer += sum_cost
    heapq.heappush(arr, sum_cost)
print(answer)