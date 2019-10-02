import re, math, decimal, bisect
def read(): return input().strip()
def iread(): return int(input().strip())
def viread(): return [int(_) for _ in input().strip().split()]
def round(n): return int(n + 0.5)

DEBUG = 1
DEBUG = 0
def debug(*args, **kwargs):
    if DEBUG: print(*args, **kwargs)

from copy import deepcopy

# code goes here
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

t = iread()
for ti in range(t):
    r, c, n = viread()
    if r == 0:
        read()
        print()
        continue
    grid = [list(read()) for _ in range(r)]
    for _ in range(n):
        new = deepcopy(grid)
        for i in range(r):
            for j in range(c):
                me = grid[i][j]
                for d in range(len(dx)):
                    _r, _c = i + dx[d], j + dy[d]
                    if _r >= 0 and _r < r and _c >= 0 and _c < c:
                        them = grid[_r][_c]
                        if me == 'R' and them == 'S' or\
                           me == 'P' and them == 'R' or\
                           me == 'S' and them == 'P':
                           new[_r][_c] = me
        grid = deepcopy(new)
        debug("\n".join(["".join(row) for row in grid]), end="...\n")
    print("\n".join(["".join(row) for row in grid]), end="\n" + ("\n" if ti < t-1 else ''))
