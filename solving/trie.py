class Node:
    def __init__(self, val, data=False):
        self.val = val
        self.data = data
        self.child = {}


class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        cur = self.head
        for ch in string:
            if ch not in cur.child:
                cur.child[ch] = Node(ch)
            cur = cur.child[ch]
        cur.data = string

    def search(self, string):
        cur = self.head
        for ch in string:
            if ch not in cur.child:
                return False
            cur = cur.child[ch]
        return cur.data is not None