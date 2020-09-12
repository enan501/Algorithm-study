from itertools import product
oper = {'cpp': 1000, 'java': 2000, 'python': 3000, 'backend': 100, 'frontend': 200, 'junior': 10, 'senior': 20,
        'chicken': 1, 'pizza': 2}

def solution(info, query):
    answer = []

    infoMap = {}
    for i in info:
        sepInfo = i.split(" ")
        key = calKey(sepInfo[:-1])
        if key in infoMap:
           infoMap[key].append(int(sepInfo[-1]))
        else:
            infoMap[key] = [int(sepInfo[-1])]
    for k in infoMap.keys():
        infoMap[k].sort()
    for q in query:
        cnt = 0
        sepQuery = q.replace(" and "," ").split(" ")
        keys = calQueryKeys(sepQuery[:-1])
        for key in keys:
            if key in infoMap.keys():
                # cnt += len(list(filter(lambda x: x >= int(sepQuery[-1]), infoMap[key])))
                if infoMap[key][-1] < int(sepQuery[-1]):
                    continue
                cnt += (len(infoMap[key]) - lowerbound(infoMap[key],int(sepQuery[-1])))

        answer.append(cnt)
    return answer

def calKey(sepInfo):

    key = 0
    for i in sepInfo:
        key += oper[i]
    return key

def calQueryKeys(sepQuery):
    keys = []
    lang = ['cpp','java','python']
    part = ['frontend','backend']
    exp = ['junior','senior']
    food = ['pizza','chicken']
    conds = [lang,part,exp,food]
    rQuery = []
    for q,index in zip(sepQuery, range(0,len(sepQuery))):
        if q == '-':
            rQuery.append(conds[index])
        else:
            rQuery.append([q])
    for rQ in list(product(*rQuery)):
        keys.append(calKey(rQ))
    return keys


def lowerbound(arr, target):
    left, right = 0, len(arr) - 1

    while (left < right):
        mid = (left + right) // 2

        if (arr[mid] < target):
            left = mid + 1
        else:
            right = mid

    return right










info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
query = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]
print(solution(info,query))