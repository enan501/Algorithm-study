def solution(prices):
    n = len(prices)
    answer = [0] * n
    rising = [0]
    for i in range(1,len(prices)):
        while rising and prices[rising[-1]] > prices[i]:
            r = rising.pop()
            answer[r] = i-r
        rising.append(i)

    while rising:
        r = rising.pop()
        answer[r] = n - 1 - r
    return answer

prices = [4,3,2,1]
print(solution(prices))

