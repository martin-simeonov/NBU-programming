def largestpossible(snippets):
    snippets = [str(s) for s in snippets]
    return ''.join(sorted(snippets, reverse=True, key=cmp_to_key(comp)))


def comp(i, j):
    x = i + j
    y = j + i

    if x < y:
        return -1
    elif x > y:
        return 1
    else:
        return 0


def cmp_to_key(mycmp):
    'Convert a cmp= function into a key= function'
    class K(object):
        def __init__(self, obj, *args):
            self.obj = obj
        def __lt__(self, other):
            return mycmp(self.obj, other.obj) < 0
        def __gt__(self, other):
            return mycmp(self.obj, other.obj) > 0
        def __eq__(self, other):
            return mycmp(self.obj, other.obj) == 0
        def __le__(self, other):
            return mycmp(self.obj, other.obj) <= 0
        def __ge__(self, other):
            return mycmp(self.obj, other.obj) >= 0
        def __ne__(self, other):
            return mycmp(self.obj, other.obj) != 0
    return K


n = raw_input()
print(largestpossible(list(map(int, raw_input().split()))))
