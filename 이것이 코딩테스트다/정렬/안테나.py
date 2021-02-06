n = int(input())
houses = sorted(list(map(int,input().split())))
print(houses[len(houses) // 2 - 1])
