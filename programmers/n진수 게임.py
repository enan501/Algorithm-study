#
# def convert(num, base):
#     tmp = "0123456789ABCDEF"
#     q, r = divmod(num, base)
#     if q == 0:
#         return tmp[r]
#     else:
#         return convert(q, base) + tmp[r]
#
# def solution(n, t, m, p):
#     answer = ''
#     total = ''
#     for num in range(t*m):
#         total += str(convert(num, n))
#     for i in range(p-1,t*m,m):
#         answer += total[i]
#     return answer
#
# n, t, m, p = 16, 16, 2, 2
# print(solution(n,t,m,p))
#
def solution(prices):
    n = len(prices)
    answer = [0] * n
    rising = [0]
    for i in range(1,n):
        while rising and prices[rising[-1]] > prices[i]:
            b = rising.pop()
            answer[b] = i - b
        rising.append(i)

    while rising:
        b = rising.pop()
        answer[b] = n-b-1

    return answer

print(solution([1, 2, 3, 2, 3]))