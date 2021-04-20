import sys
n = int(sys.stdin.readline())
st = [(0,False)] * n * 2
for i in range(n):
    x, y = map(int,sys.stdin.readline().split())
    st[i*2], st[i*2+1] = (x,True), (y,False)
st.sort()
answer, lines, first_pos = 0, 0, 0
for num, isStart in st:
    if isStart:
        if lines == 0:
            first_pos = num
        lines += 1
    else:
        lines -= 1
        if lines == 0:
            answer += num - first_pos
print(answer)
