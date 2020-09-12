from itertools import combinations
def solution(orders, course):
    answer = []

    for c in course:
        setList = []
        setMap = {}
        for order in orders:
            order = list(order)
            order.sort()
            comb = set(combinations(order,c))
            for new in comb - set(setList):
                setMap[new] = 1
            for old in comb & set(setList):
                setMap[old] += 1
            setList = list(set(setList) | comb)
        if len(setMap) == 0:
            break
        vMax = max(setMap.values())
        if vMax > 1:
            keys = getKeysByValue(setMap, vMax)
            for key in keys:
                answer.append("".join(key))
    answer.sort()
    return answer

def getKeysByValue(sMap, v):
    keys = list()
    items = sMap.items()
    for item in items:
        if item[1] == v:
            keys.append(item[0])
    return keys

orders = ["XYZ", "XWY", "WXA"]
course = 	[2,3,4]
print(solution(orders,course))
