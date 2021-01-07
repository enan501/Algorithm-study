nums = list(map(int,input()))
answer = nums[0]
for next_num in nums[1:]:
    if answer < 2 or next_num < 2:
        answer += next_num
    else:
        answer *= next_num
print(answer)
