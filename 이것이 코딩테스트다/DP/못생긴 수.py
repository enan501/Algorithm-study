from bisect import insort
n = int(input())
ugly = [1]
for i in range(n):
    if ugly[i] != int(ugly[i] / 3) * 3 and ugly[i] != int(ugly[i] / 5) * 5:
        insort(ugly, ugly[i] * 2)
    if ugly[i] != int(ugly[i] / 5) * 5:
        insort(ugly, ugly[i] * 3)
    insort(ugly, ugly[i] * 5)
print(ugly[n-1])