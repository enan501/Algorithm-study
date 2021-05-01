import re
from itertools import product
def solution(user_id, banned_id):
    candidates = []
    for b in banned_id:
        b = b.replace("*", ".")
        matches = []
        for u in user_id:
            if re.fullmatch(b, u):
                matches.append(u)
        if matches:
            candidates.append(matches)
    li = []
    for candidate in product(*candidates):
        if len(candidate) == len(set(candidate)):
            li.append(tuple(sorted(candidate)))
    return len(set(li))




user_id = ["frodo", "fradi", "crodo", "abc123", "frodoc"]
banned_id = ["fr*d*", "*rodo", "******", "******","a"]

print(solution(user_id,banned_id))