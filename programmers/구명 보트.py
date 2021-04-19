def solution(people, limit):
    answer = 0
    li, hi = 0, len(people) - 1
    people.sort()
    while li <= hi:
        if people[hi] + people[li] <= limit:
            li += 1
        hi -= 1
        answer += 1
    return answer

print(solution([70, 50, 80, 50],100))