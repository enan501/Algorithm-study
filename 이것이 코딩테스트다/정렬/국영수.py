import sys
n = int(input())
arr = [ () for _ in range(n)]
for i in range(n):
    name, kor, eng, mth = sys.stdin.readline().split()
    arr[i] = (int(kor) * -10101 + int(eng) * 101 + int(mth) * -1, name)
arr.sort(key = lambda x: (x[0], x[1]))
for student in arr:
    print(student[1])
