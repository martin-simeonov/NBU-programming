def largestpossible(snippets):
    snippets = [str(s) for s in snippets]
    mlen = max(len(s) for s in snippets) * 2
    return ''.join(sorted(snippets, reverse=True,
                          key=lambda s: s * (mlen//len(s) + 1)))


raw_input()
print(largestpossible(list(map(int, raw_input().split()))))
