from itertools import permutations


def cal(ops, ind, exp):
    if ind == 3:
        return int(exp)
    nums = exp.split(ops[ind])
    result = cal(ops, ind+1, nums[0])
    if len(nums) == 1:
        return result
    for num in nums[1:]:
        if ops[ind] == '*':
            result *= cal(ops,ind+1,num)
        elif ops[ind] == '+':
            result += cal(ops,ind+1,num)
        elif ops[ind] == '-':
            result -= cal(ops,ind+1,num)
    return result


def solution(expression):
    answer = 0
    for order in permutations("*-+",3):
        answer = max(answer, abs(cal(order, 0, expression)))
    return answer

print(solution("100-200*300-500+20"))