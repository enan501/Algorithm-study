def solution(s):
    answer = []
    arr = s[2:-2].split("},{")
    arr.sort(key=len)
    lastList = set([])
    for item in arr:
        currentList = set(item.split(","))
        answer.append(int(list(currentList - lastList)[0]))
        lastList = currentList
    return answer