def solution(s):
    answer = [0,0]
    while s != "1":
        ones = s.count('1')
        answer[1] += len(s) - ones
        s = bin(ones)[2:]
        answer[0] += 1
    return answer

print(solution("110010101001"))