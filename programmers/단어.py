def is_only_diff_one(w1, w2):
    cnt = 0
    if len(w1) == len(w2):
        for c1, c2 in zip(w1, w2):
            if c1 != c2:
                cnt += 1
                if cnt > 2:
                    break
    return cnt == 1


def solution(begin, target, words):
    answer = int(1e9)
    n = len(words)
    target_index = -1
    for i in range(n):
        if target == words[i]:
            target_index = i
    if target_index == -1:
        return 0

    arr = [[int(1e9) for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            if is_only_diff_one(words[i], words[j]):
                arr[i][j] = 1
                arr[j][i] = 1

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if i != j and arr[i][j] > arr[i][k] + arr[k][j]:
                    arr[i][j] = arr[i][k] + arr[k][j]

    for i in range(n):
        if is_only_diff_one(begin, words[i]):
            answer = min(answer, arr[i][target_index])

    if answer == int(1e9):
        answer = 0
    else:
        answer += 1
    return answer

begin, target, words = "hit","cog",["hot", "dot", "dog", "lot", "log", "cog"]
print(solution(begin,target,words))