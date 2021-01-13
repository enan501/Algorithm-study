def solution(s:str):
    answer = len(s)
    for length in range(1,len(s)//2+1):
        compressed_len, count = len(s), 0
        compressed_words = [s[i:i+length] for i in range(0, len(s), length)]
        prev = compressed_words[0]
        for compressed_word in compressed_words[1:]:
            if compressed_word == prev:
                count += 1
            elif count > 0:
                compressed_len += (len(str(count+1)) - length * count)
                count = 0
            prev = compressed_word
        if count > 0:
            compressed_len += (len(str(count+1)) - length * count)
        answer = min(answer, compressed_len)
    return answer

print(solution("xxxxxxxxxxyyy"))