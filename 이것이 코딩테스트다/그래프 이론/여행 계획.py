import sys
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

# # 플로이드
# arr = [[] for _ in range(n)]
# for i in range(n):
#     arr[i] = list(map(lambda x: int(x) if x != '0' else int(1e9), sys.stdin.readline().split()))
#     arr[i][i] = 1
#
# for k in range(n):
#     for i in range(n):
#         for j in range(n):
#             arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j])
#
# plan = list(map(int,sys.stdin.readline().split()))
# answer = "YES"
# for i in range(len(plan)-1):
#     if arr[plan[i]-1][plan[i+1]-1] == int(1e9):
#         answer = "NO"
#         break
#
# print(answer)

# 유니온-파인드
def find(parent,x):
    if parent[x] != x: # 루트가 아니라면 루트를 찾을 때까지 재귀 호출
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent,a,b):
    a = find(parent, a)
    b = find(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

parent = [i for i in range(n)]

for i in range(n):
    data = list(map(int, sys.stdin.readline().split()))
    for j in range(i,n):
        if data[j] == 1:
            union(parent, i, j)

plan = list(map(int,sys.stdin.readline().split()))
answer = "YES"
for i in range(len(plan)-1):
    if find(parent,plan[i]-1) != find(parent, plan[i+1]-1):
        answer = "NO"
        break

print(answer)