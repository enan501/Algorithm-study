import sys
t = int(sys.stdin.readline())
for _ in range(t):
    p, m, f, c = map(int,sys.stdin.readline().split())
    chicks = m // p
    coupons = chicks * c
    sang = chicks + (coupons // f)
    du = chicks + (1 + ((coupons - f) // (f - c)) if coupons >= f else 0)
    print(du - sang)