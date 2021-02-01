def solution(p:str):
    if p == "": return p
    u, v = "", ""
    balance = 0
    for i, ch in enumerate(p):
        balance += 1 if ch == '(' else -1
        if balance == 0:
            u, v = p[:i+1], p[i + 1:]
            break
    if u[0] == ')':
        return '(' + solution(v) + ')' + ''.join([')' if ch == '(' else '(' for ch in u[1:-1]])
    else:
        return u + solution(v)