from itertools import combinations
def solution(relation):
    answer = 0
    cols = len(relation[0])
    n = len(relation)
    columns = [[] for _ in range(cols)]
    cand = []
    for i in range(cols):
        for r in relation:
            if r[i] in columns[i]:
                cand.append(i)
                break
            else:
                columns[i].append(r[i])
        if len(columns[i]) == n:
            answer += 1

    for i in range(1,len(cand)+1):
        ccols = combinations(cand,i)
        # for ccol in ccols:




    return answer


relation = [["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]]
print(solution(relation))
