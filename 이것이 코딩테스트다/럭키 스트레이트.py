nums = list(map(int,input()))
n = len(nums)
left, right = 0, 0
for i, num in enumerate(nums):
    if i < n/2:
        left += num
    else:
        right += num
if left == right:
    answer = "LUCKY"
else:
    answer = "READY"
print(answer)