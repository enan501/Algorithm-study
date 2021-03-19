
class Node:
    def __init__(self, val, cnt=0):
        self.val = val
        self.cnt = cnt
        self.child = {}


class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        cur = self.head
        cur.cnt += 1
        for ch in string:
            if ch not in cur.child:
                cur.child[ch] = Node(ch)
            cur = cur.child[ch]
            cur.cnt += 1

    def search(self, string):
        cur = self.head
        for ch in string:
            if ch == '?':
                break
            elif ch not in cur.child:
                return 0
            cur = cur.child[ch]
        return cur.cnt

def solution(words, queries):
    answer = []
    trie = [Trie() for _ in range(10001)]
    eirt = [Trie() for _ in range(10001)]
    for word in words:
        trie[len(word)].insert(word)
        eirt[len(word)].insert(word[::-1])
    for query in queries:
        if query[0] == '?':
            answer.append(eirt[len(query)].search(query[::-1]))
        else:
            answer.append(trie[len(query)].search(query))
    return answer

words = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
queries = ["fro??", "????o", "fr???", "fro???", "pro?","?????"]

print(solution(words,queries))