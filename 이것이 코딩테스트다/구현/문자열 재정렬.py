s = input()
alpha, num = "", 0
for ch in s:
    if ch.isalpha():
        alpha += ch
    else:
        num += int(ch)
print(''.join(sorted(alpha)) + (str(num) if num > 0 else ""))
