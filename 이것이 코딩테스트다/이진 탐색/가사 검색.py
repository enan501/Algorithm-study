from bisect import bisect_right, bisect_left


def solution(words, queries):
    answer = []
    words.sort()
    reversed_words = []
    for word in words:
        reversed_words.append(word[::-1])
    cwords = []
    for query in queries:
        queryz = ""
        if query[0] == '?':
            query = query[::-1]
            cwords = reversed_words
        for i in range(len(query)):
            if query[i] == '?':
                queryz += 'z'
            else:
                queryz += query[i]
        left = bisect_left(cwords, query)
        right = bisect_right(cwords, queryz)
        count = 0
        for i in range(left, right):
            if len(cwords[i]) == len(query):
                count += 1

        answer.append(count)
    return answer