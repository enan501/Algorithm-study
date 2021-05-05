import re
from itertools import product
def solution(user_id, banned_id):
    candidates = []
    for b in banned_id:
        matches = list(filter(lambda u: re.fullmatch(b.replace("*", "."),u), user_id))
        if matches:
            candidates.append(matches)
    li = map(lambda x: frozenset(x), filter(lambda c: len(c) == len(set(c)), product(*candidates)))
    return len(set(li))




user_id = ["frodo", "fradi", "crodo", "abc123", "frodoc"]
banned_id = ["fr*d*", "*rodo", "******", "******","a"]

print(solution(user_id,banned_id))