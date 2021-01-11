n = int(input())
coins = list(map(int,input().split()))
coins.sort()
answer = coins[0]+1 if coins[0] == 1 else 1
for coin in coins[1:]:
    if answer >= coin:
        answer += coin
    else:
        break
print(answer)
